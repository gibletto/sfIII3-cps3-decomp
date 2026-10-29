# How 3rd Strike works

A tour of the Street Fighter III: 3rd Strike arcade program, written from this source. It's aimed at people who can
read C and want to know how the game hangs together: where a frame starts, how a button press becomes a fireball,
why the code is shaped the way it is.

A few things to know before you start:

- The CPU is a Hitachi SH-2 running at roughly 25 MHz. That isn't much, so most of the design is about doing as
  little work per frame as possible: look things up in tables instead of computing them, and let the video hardware
  do the heavy lifting.
- Names like `Game00`, `G_No1`, `Basic_Sub` or `ryu_saca` are Capcom's (many came from debug symbols on a PS2
  release). Names marked "provisional" in the source are ours, and some are better than others. Where a name is
  misleading, this document says so.
- "Frame" means one video frame, about 1/60 of a second. Almost everything in the game is counted in frames.

---

## The big picture

The whole game is a loop that runs once per frame:

```
vblank interrupt  ->  wake the game tasks
game task         ->  read state, run the current scene, move every object, check hits, build a sprite list
vblank interrupt  ->  hand that sprite list and the new scroll/palette values to the video hardware
```

The CPU never draws pixels. It writes *descriptions* (sprite X/Y, which tile, which palette, how far each background
layer has scrolled) and the CPS3 video chip turns those into a picture. The game's job each frame is to update a few
hundred small structs and write those descriptions in time.

---

## Boot-up

When the board powers on, the SH-2 reads its vector table (`data/vectors.c`, linked at 06000000). Entry 0 is the
start address, `reset_entry`, and entry 1 is the starting stack pointer.

`reset_entry` (in `src/tasksw.src`, assembler) does the bare-metal setup:

1. Zero the RAM for variables that start at 0, and copy the initial values of the other variables from ROM into RAM.
   This is what a C runtime normally does before `main`, done by hand.
2. Set up the SH-2 timer and a video register.
3. Read the region from the BIOS and load default settings.
4. Initialise the sound driver.
5. Create the first task, `boot_task`, then jump into the scheduler, `Game_Task`, which never returns.

From there it's all tasks. `boot_task` creates `mode_init_task`, which does the game-level setup:

- work out the region and country
- set up sprite lists, palettes and the font
- load the operator settings from EEPROM (`eeprom_config_load`), resetting them to defaults if the checksum is bad
- clear every game-state variable, and hand out 9 credits if free play is on
- show the region text and the warning screen
- start the two tasks that run the actual game, `game_frame_task` and `entry_task`, then end itself

---

## The loop: tasks and vblank

There's no operating system, just a tiny cooperative task switcher. Think of it as a shared kitchen with eight
cooks and one stove: each cook uses the stove until they choose to step away, and nobody gets pushed off.

- There are 8 task slots (`task_tbl[8]`), each with its own 1 KB stack.
- `Game_Task` (`src/Entry.c`) walks the slots in order and runs any task that's ready.
- A task gives up the CPU by calling `task_sleep(n)` ("wake me in n frames") or `task_wait()` ("I'm ready again
  straight away"). The assembler in `tasksw.src` saves its registers and returns to the scheduler.
- The vblank interrupt counts the sleep timers down, so `task_sleep(1)` means "run again next frame".

Here's the task that runs the game. The whole game is a loop of four lines:

```c
void game_frame_task(void) {
loop:
    bg0001();            /* run whatever scene we're in */
    color_trans_dummy(); /* empty in this build */
    sprite_bank_flip();  /* this frame's sprite list is done */
    task_sleep(1);       /* see you next frame */
    goto loop;
}
```

The speed comes entirely from that `task_sleep(1)`. There's no timing code anywhere; the game runs at the
display's rate because it waits for each vblank.

### The vblank interrupt

The vblank (vertical blank) is the short gap after the screen has been drawn, before the next one starts. It's the
safe moment to change what the video chip is reading. `_vblank_frame_dispatch` (`src/intr.src`) does this each frame:

1. Bump the frame counter (`system_timer`) and set `vsync_flag`.
2. Push the finished frame to the hardware: scroll positions, zoom, layer windows.
3. Read the joysticks and buttons, and handle coins (yes, coin handling happens inside the interrupt).
4. Tick the task sleep timers.
5. Copy the finished sprite list into sprite RAM.
6. Tick the sound driver.

So the work is split in two: **logic happens in tasks, and committing it to the hardware happens in the interrupt.**
The logic for frame N runs while the video chip shows frame N-1.

### Slow motion

The KO slow-down is a nice trick. At the top of every fight frame:

```c
EXE_flag = Game_timer % (SLOW_flag + 1);
```

Objects only move when `EXE_flag == 0`. With `SLOW_flag` at 1, logic runs every other frame; at 2, every third.
The screen keeps updating at full rate (sprites are still drawn, the background still scrolls), but the world moves
in slow motion. A KO sets a 95-frame slow timer that eases back to normal through a table.

---

## Game states

The game is a stack of state machines, and they all use the same pattern: a small number says where you are, and
a table of function pointers says what to do there. Capcom call the number an "rno" (routine number).

```c
void bg0001(void) {
    void (*Main_Jmp_Tbl[3])() = { match_state_0_fight, game_phase_dispatch, Game_Dummy };
    Main_Jmp_Tbl[G_No0]();
}

void game_phase_dispatch(void) {
    void (*Game_Jmp_Tbl[12])() = { Game00, Game01, Game02, Game03, Game04, Game05,
                                   Game06, Game07, Game08, Game09, Game10, Game11 };
    Game_Jmp_Tbl[G_No1]();
}
```

It's a lift with numbered floors: `G_No0` picks the building, `G_No1` the floor, `G_No2` and `G_No3` the room.
Moving on is just `G_No2++`, or setting `G_No1` and zeroing the levels below it. No `if` chains, no
string compares, one indexed jump per level. That's cheap on an SH-2 and easy to extend: add a scene, add a row.

The top levels:

| `G_No0` | `G_No1` | Scene |
|---|---|---|
| 0 | 1-6 | attract mode: logo, title, demos, rankings (`match_state_0_fight`, whose name is misleading) |
| 1 | 0 | title / start |
| 1 | 1 | player select |
| 1 | 2 | the fight |
| 1 | 3, 4 | winner / loser scene |
| 1 | 5 | next CPU opponent |
| 1 | 6 | game over / name entry, then back to attract |
| 1 | 7 | continue |
| 1 | 8 | ending and final grade |
| 1 | 9, 10 | bonus stage and after |

Other systems have their own counters with the same idea: `E_No*` for the coin and start-button task, `C_No*` for
round management, `D_No*` for attract scenes, `S_No` for character select. Every object on screen has one too
(`routine_no[8]` in its `WORK` struct).

Test mode is different: it's its own task. When the test switch is pressed, it kills the game tasks, runs the
menu, and when you leave, it restarts `mode_init_task` as if the board had rebooted.

---

## Shared state

Global variables live at fixed RAM addresses. Each module defines the variables it owns, the shared game state is in
`src/workuser.c`, and `src/work.c` keeps a few settings. Every definition has its RAM address in a comment, which is
handy when you're poking at a running game in an emulator:

```c
PLW plw[2]; /* 02068C6C */
```

The ones you'll meet everywhere:

- **Scene counters:** `G_No0..3`, `E_No0..3` and friends (above).
- **`Demo_Flag`:** reads backwards. It's **0 during attract mode** and 1 in a paid game. So "is this a real game?"
  is `if (Demo_Flag)`.
- **The players:** `plw[2]`, one `PLW` each. A `PLW` starts with a `WORK`, the base struct for every object on
  screen (fighters, fireballs, sparks, stage props), so the same code can move, draw and hit-check any of them.
- **Match state:** `Round_num`, `PL_Wins[2]`, `Score[2][3]`, `My_char[2]`, `Super_Arts[2]`, the round timer.
- **Credits:** `credit_1p..credit_4p`, in BCD (each nibble one decimal digit, which makes drawing numbers trivial).
- **Settings:** `Game_setting` and friends, filled from EEPROM at boot. Difficulty, round count, timer speed, free
  play and so on all come from here.

### Coins and free play

Coins are read twice a frame (once from vblank, once from a mid-frame timer interrupt) and each sample is shifted
into a little history byte. A coin only counts once the history shows a clean press and release:

```c
if ((coin_sw_hist[n] & 0xF) == 0x3)        /* 0011: closed for two samples -> coin arriving */
    ...
else if ((coin_sw_hist[n] & 0xF) == 0xC)   /* 1100: open again for two samples -> coin dropped */
    ...
```

Matching a 4-bit pattern is a cheap way to ignore a switch that bounces. After that, coins become credits using the
coin rate from the settings (2 coins, 1 credit, etc.), capped at 9, and a mechanical coin meter is pulsed through
an output latch.

Free play is just a coin setting. When it's on, `entry_main` sets both players' credits to 9 every frame and the
coin chutes are locked. Text like "INSERT COIN", "FREE PLAY" or "PRESS 1P START" is picked by `Disp_Start_Message`
from the credit count and the settings, and blinks 50 frames on, 30 off.

---

## Inputs and interrupts

### Reading the controls

`switch_read_six_button` runs in vblank. The ports read 0 for "pressed", so the code inverts them, and keeps last
frame's value next to this frame's:

```c
p1sw_1 = p1sw_0;                                          /* last frame */
p1sw_0 = ~(s16)(*(volatile u16*)(IO_REG + 0x2)) % 256U;   /* this frame */
```

With both values you can tell "just pressed" from "held". This idiom is everywhere:

```c
if (~p1sw_1 & p1sw_0 & BUTTON_START)   /* Start (0x1000) went down this frame */
```

The lever is 4 bits (1 up, 2 down, 4 left, 8 right), then the buttons, coin and Start.

### Into the fighters

Each frame, a fighter's input goes through `pl_lvr_set`, which does two clever things:

- **It flips left and right when the fighter faces the other way** (`work2 ^= 0xC`). After this, the lever bits mean
  "forward" and "back" instead of "left" and "right". So every special move only has to be written once, facing one
  way, and it works from either side of the screen.
- **It builds edge words:** `sw_now` (just pressed), `sw_new` (held), `sw_chg` (pressed *or released*). `sw_chg`
  is why you can "negative edge" a special move by releasing the button.

It also adds a synthetic "two punches" bit (0x80) and "two kicks" bit (0x800), which is how EX moves are detected:
the move data just asks for that bit.

If the side isn't human, `CPU_Sub` (the AI in `Com_Pl.c`) produces a fake joystick value instead, and it goes
through exactly the same code. The AI plays with a virtual controller.

### The interrupts

| Interrupt | What it's for |
|---|---|
| vblank | the frame: input, coins, hardware updates, sprite list, sound, task timers |
| sprite DMA done | start the next queued graphics or palette transfer |
| SH-2 timer | an extra mid-frame coin sample |
| CPU errors | save every register and stop (`cpu_hang_forever`) |

There's no separate sound interrupt; the sound driver is a software sequencer ticked from vblank.

---

## Drawing

The video hardware does the drawing. The game writes lists. Two naming traps in the source first:

- In `cram_bank.c`, "CRAM" means **character RAM** (tile pixels), not palette RAM.
- The `polygon2d_*` functions don't draw polygons. They're the DMA calls that copy graphics and palettes.

### Graphics come from ROM, by number

The art isn't in this source; the build reads it from your ROM. Code refers to art by **pattern number**. Each
object has a `cg_number`, which indexes `cg_data_tbl`. That entry says which compressed chunks to copy from the
graphics ROM into tile memory and how to lay the tiles out as sprite cells.

The tiles are cached by slot (`cg_slot_tbl`), so when a fighter's animation moves to a pattern that shares a slot,
nothing is copied again. Loading art is slow, and this keeps it to the frames where something new appears.

### Sprites: build a list, flip, let the hardware draw it

Every visible object calls something like `push_char_sprite` once a frame:

```c
spr[0] = wk->spr.gfx_cells | (wk->my_family << 12);   /* how many cells, which scroll group */
spr[1] = wk->spr.gfx_ofs;                             /* where its cell table is */
spr[2] = wk->position_x;
spr[3] = wk->position_y + y_ofs;
spr[4] = wk->spr.disp_colcd | wk->my_col_mode | flip_attr_tbl[wk->spr.sprite_flip];
sprite_entry_push_prio(spr, wk->position_z);          /* drop it in a depth bucket */
```

- **Depth:** entries go into one of 128 buckets by `position_z`, and each bucket is a linked list. Sorting by
  dropping things into numbered bins is far cheaper than sorting the whole list.
- **Double buffering:** there are two pools. The game fills one while the hardware reads the other, and
  `sprite_bank_flip` swaps them at the end of the frame. In vblank, `sprite_display_list_build` walks the finished
  pool bucket by bucket and writes it into sprite RAM.
- **Flipping:** a sprite facing left is the same art with a flip bit, from a 4-entry table
  (`{0, 0x1000, 0x800, 0x1800}` for none, X, Y, both). Each cell's offset is negated for the flip.

### Backgrounds

There are four tilemap layers plus a text layer. A stage is set up by `bg_initialize`: look up the stage's
background, DMA its tiles and palette, and fill each layer's map. Every frame after that, the stage's own routine
(`BG000`, `BG010`, ...) moves each layer by its own fraction of the camera movement. Far layers move slowly, near
layers fast, and that's your parallax.

Two tricks worth knowing:

- **Families:** each layer has a "family" number, and so do sprites. The hardware offsets every sprite by its
  family's position. So a stage prop (a dog, a bin, a crowd member) set to the same family as its layer scrolls
  with that layer automatically, with no per-object math.
- **Line scroll:** each scanline of a layer can have its own X offset. Stage floors use this: the top rows shift
  one way, the bottom rows the other, scaled with the camera, and a flat floor graphic looks like it's in
  perspective.

### Colour

Palettes are loaded by DMA from tables of `{source, destination, size}`. Fades are done by the hardware during the
copy (the DMA takes brightness values), so a fade costs one transfer per step. The white flash when a fighter is hit
is a temporary colour code (`extra_col`) that replaces the object's palette when its sprite is pushed. No colours
are recomputed.

### Text

The text layer is a grid of cells in its own RAM. `tilemap_put_char(x, y, attr, code)` writes one cell, and
`tilemap_print_string` prints records of `{x, y, attr, string}`. Credits, the timer digits, combo messages and
the test menus all go through this.

---

## Attract mode

Attract mode runs when nobody's paid. It's scene state `G_No0 == 0`, and `G_No1` steps through:

1. **Capcom logo:** fade in, animate, hold, fade out.
2. **Opening movie and title:** this is synced to the music. Each scene waits until the music sequencer reaches a
   given position (`op_change_sound_tbl`), so the visuals cut on the beat no matter what.
3. **Select demo:** a recorded player-select screen.
4. **Ranking board.**
5. **Fight demo:** CPU vs CPU.
6. **Ranking board** again, then back to the logo.

`Ck_Coin()` is checked first every frame. A coin, a credit, or Start under free play jumps straight into the game.

### How things animate

Almost everything on these screens is an **effect object**: a `WORK` struct in a pool of 128, with a type number.
Each frame, `move_effect_work` walks the active lists and calls the right routine for each type from a table
(`effmovejptbl[id]`). Logos, ranking digits, faces, wipes, even "play this sound at frame 200" are all little effect
objects with their own state machines. Spawning one is "grab a free slot, set its type and starting values".

### The demos

- **Fight demos use the real AI.** Both sides are just CPU players (`operator == 0`), running the same AI as the
  arcade opponent. The fighters come from a short list (Chun-Li v Remy, Ken v Twelve, Ryu v Makoto, Sean v Elena),
  with a random Super Art and one of the two home stages. To stop it being an even mirror match, one side is
  randomly made the weak one (`Weak_PL`), and the AI checks that flag to play worse. The demo runs the real fight
  code for 1800 frames, or ends 90 frames after a KO.
- **The select demo is recorded.** The cursor movements and button presses replay from a table of input frames
  (`Demo_Lever_Data`), read in place of the joystick. Once the select screen is done, both sides become CPU for the
  fight.

### Sound

The sound driver is software: `sound_request(code)` starts a sequence (music or effect) that the vblank tick plays
through 32 voices. The attract wrappers check the "demo sound" operator setting first, so a silent cabinet stays
silent until someone pays.

---

## Player select

`Select_Player` runs each frame of the select screen: the screen-wide part (timer, background, music), then one
pass for each human player.

- **Character:** the cursor moves around a 3x7 grid table (`Face_Cursor_Data`), with key-repeat after a short hold.
  Gill isn't on the grid.
- **Colour:** whichever button you press picks the colour. If the other player already has that character in that
  colour, you get the alternate. A three-button press is collected over 3 frames for the extra colour.
- **Super Art:** up and down choose one of three, and the button confirms.
- **Timer:** a countdown runs, and when it hits zero the code fakes a button press, which picks whatever's
  highlighted.

### The CPU path

When you confirm, the game builds your whole run up front (`Initialize_EM_Candidate`): two candidate opponents for
each of the first 8 stages, drawn at random without repeats, then your rival, then Gill. Some characters are held
back: Ryu, Ken, Hugo and Elena can't appear before stage 5, Akuma not before stage 7. Before each fight you pick
between that stage's two candidates. Their Super Art is random, kept for the rest of the run.

### Into the fight

After the last selection: fade out, play the VS jingle, show the VS screen for 180 frames, set the stage, and
switch `G_No1` to the fight. The stage is the opponent's home stage. In versus it's the challenger's.

---

## The fight

`Game2_1` is one frame of the fight, and the order matters:

```
Game_timer++, slow-motion check, round clock
Player_control          -> both fighters think and move
vital_cont_main         -> health bars
combo_cont_main         -> combo counter and messages
TATE00                  -> the stage
Game_Management         -> round start/end
move_effect_work(0..6)  -> every effect: fireballs, sparks, stage props
hit_check_main_process  -> collisions
```

Hits are judged **at the end of the frame, after everything has moved**, and their results are applied next frame
when each fighter runs. Nobody can hit you halfway through your own update, which keeps the outcome independent of
who happened to be processed first.

### The stage

The stage is a state machine of its own (`TATE00`): load, set up, then run the stage routine every frame. Each
stage starts its scenery effects: snow, animals, breakable bins, a crowd member who turns to face "his" fighter.

The camera follows the fighters. Their screen positions are sorted into zones, and the pair of zones picks a
scroll routine from a 2D jump table (`scr_x_mv_jp[(hi<<4)+lo]`). Scrolling is capped per frame and eased to 80%,
then clamped to the stage edges. An animation frame can ask for a cinematic recentre (on P1, P2, or between them),
and the camera glides there over 6 frames.

---

## Fighters

### The state machine

A fighter is a `PLW`. Its `routine_no` array is a four-level address:

- `routine_no[0]`: life phase (init, entry, intro pose, fighting)
- `routine_no[1]`: class: **0 normal, 1 damage, 2 throwing, 3 being thrown, 4 attacking**
- `routine_no[2]`: the move or sub-state (stand, crouch, walk, jump, parry, or which attack)
- `routine_no[3]`: the step within it (usually 0 = start the animation, 1 = play it)

`Player_move` reads the input and runs the command check, then calls through a table on `routine_no[0]`. In the
fighting phase that becomes a table on `routine_no[1]` (`Player_normal`, `Player_damage`, `Player_catch`,
`Player_caught`, `Player_attack`), and each of those has a table on `routine_no[2]`. Getting hit is just the hit
code writing `routine_no[1] = 1` into the defender: next frame they're in the damage routine, whatever they were
doing.

### Deciding what to do

While standing, `nm_01000` checks the possible actions in a fixed order, and the first match wins:

1. Supers (EX gauge and Super Art)
2. Special moves
3. Taunt
4. Throw
5. Normal attacks
6. Turning, dashing, jumping, crouching, guarding, walking

That order is the game's input priority. If a special and a normal both match, you get the special. Other states
(crouching, jumping, mid-attack) use shorter versions of the same list. During an attack, the special and super
checks only run while the current animation frame has its cancel window open.

### Special moves: little state machines, not a history buffer

You might expect the game to keep a list of recent inputs and search it for "down, down-forward, forward". It
doesn't. Each fighter has 56 command slots, and each slot is a tiny state machine that advances one step when its
next input arrives, within a time limit. Here's Ryu's fireball motion:

```c
const s16 p2_cmd_29[25] = {  /* Ryu: Hadoken, 236+P */
    CMD_RESET, CMD_LV_UP, 0, CMD_WAZA(RYU_HADOKEN), CMD_BT_CHG | CMD_BT_EX | CMD_BT_SHELL, CMD_EX_PUNCHES,
    CMD_LEVER(0, CMD_LV_DOWN),                       /* step: lever == down              */
    CMD_LEVER(10, CMD_LV_DOWN | CMD_LV_FORWARD),     /* step: lever == down+forward, 10f */
    CMD_LEVER(10, CMD_LV_FORWARD),                   /* step: lever == forward, 10f      */
    CMD_END,
};
```

- The header says: once complete, stay valid for 12 frames; pressing up cancels it; which routine to run for each
  strength; which button word to check; and which buttons mean light, medium, heavy and EX.
- Each step is `{type, frames allowed, -, lever}` (`CMD_LEVER`). The `0x8000` bit on the lever value
  (`CMD_EXACT`) means "exactly this direction". The first step has a 0-frame window, so it just waits for "down"; each later step has 10 frames.

When the last step matches, the slot sets `waza_flag[29] = 12`, and that flag counts down. The button check looks
at the flags, so you can finish the motion and press the button a few frames later.

This is cheap: each slot does one comparison per frame, and the data for every motion in the game is a short array
of numbers that a designer can change without touching code.

### Animation: a little scripting language

A move's animation is a **script**, an array of `u16` in the character's data file. Each line is either a
**frame** (show this for N frames) or a **command** (jump, loop, call, branch on input). A frame line carries
everything that happens on that frame:

| Field | What it does |
|---|---|
| `ctr` | how many frames to show this line |
| `type` | marker the state code polls (0xFF = "move over") |
| `se` | sound to play |
| `number` | sprite pattern to show |
| `att` | which attack-data row is live (negative = start a new hit) |
| `hit` | which hit-box row to use |
| `cancel` | which cancels are allowed right now |
| `effect`, `eftype` | spawn an effect object (a spark, a fireball, dust) |
| L6 lines add | camera zoom, movement step, next-line jump, position of a thrown opponent |

Each tick, `char_move` counts `ctr` down. When it hits 0, `check_cm_extended_code` reads the next line. If it's a frame,
its fields are copied straight into the fighter's struct (`check_cgd_patdat`). If it's a command, it runs and the
interpreter keeps going.

Commands chain scripts together: jump to another script, call one like a subroutine and return, loop N times,
or branch on the lever, a button, or a script variable. Target combos are done with "remember this jump target"
commands, and different strengths of a move often jump into a shared tail, so they all recover the same way.

**Starting an animation** is `set_char_move_init(wk, kind, index)`: look up `char_table[kind][index]`, copy the
script's header (stored just *before* the script in memory, read backwards), reset the counters, and run the first
line straight away.

**Interrupting** one is just starting another. A cancel starts the next move's script, getting hit switches the
fighter to the damage routine (which starts a damage script), and hit stop simply skips the fighter's update so
the script freezes in place. There's no blending between animations; sprite art is drawn to flow, and the script
picks the frames.

---

## Fighting

### Hit boxes

Each frame line names a row in the character's hit-box table, and that row names up to:

- 4 **body** boxes (where you can be hit)
- 4 **hand** boxes (extended limbs, also hittable)
- 4 **attack** boxes
- a **throw reach** box and a **throwable** box
- a **push** box (stops fighters overlapping)

Every box is `{x, width, y, height}` relative to the fighter, and X is mirrored when they face the other way. Every
object that can hit or be hit adds itself to a queue during its update (`hit_push_request`). At the end of the
frame, `attack_hit_check` tests every attacker's attack boxes against every defender's boxes with a mirrored
rectangle overlap test, written with unsigned compares so each axis is one comparison. It returns *how much* they
overlap, and when several things hit the same target, the deepest overlap wins.

Note that a defender's own attack boxes are in the list of hittable boxes. Sticking a limb out makes it a target,
which is why a well-timed poke can beat a slower attack that reaches further.

### Frame data

There's no "startup / active / recovery" table anywhere. Frame data is just the animation script. Ryu's standing
light punch:

```c
L4(2, 0,   0, 0,0,0,0, 0x0D80,  0,  1, 0,   0,  0,  0, 0),   /* 2 frames, no attack     */
L4(1, 0, 268, 0,0,0,0, 0x0D81,  0,  1, 0,   0,  0,  0, 0),   /* 1 frame, whoosh sound   */
L4(1, 0,   0, 0,0,0,0, 0x0D82, -3, 19, 0, 128, 96,  0, 0),   /* new hit: attack row 3   */
L4(2, 0,   0, 0,0,0,0, 0x0D83,  0, 20, 0,   0, 96,  0, 0),   /* still active            */
L4(2, 0,   0, 0,0,0,0, 0x0D83,  0, 21, 272, 0,  8, 21, 0),   /* boxes gone: recovery    */
...
L4(250, 255, ...)                                            /* hold pose, move over    */
```

Read the durations: 3 frames before the attack, then the attack row is live for 3 frames (hit-box rows 19 and 20
have attack boxes, row 21 doesn't), then recovery. Change a number, and the frame data changes. The attack row
(`att -3`) points at the move's properties: damage, stun, reaction, guard rules, and hit stop for each side.

Hit stun and block stun work the same way: they're the length of the damage animation the hit picks.

### What a hit does

On a hit, the damage is worked out in layers, each a table lookup or a multiply:

1. Base damage from the attack row, times a difficulty rate (90% to 112%, moving up or down with your results).
2. Times the attacker's and defender's power-ups (taunts boost these).
3. Times a bonus for hitting a defender in certain states, 1.25x, 1.5x or 2x. We think these are counter hits, but
   haven't confirmed it.
4. Combo scaling: the more hits already taken, the further down a table of 32nds you go.
5. "Guts": below 60% health, damage taken is reduced, then scaled by the character's durability.

Then hit stop: the attacker freezes for `hs_me` frames and the defender for `hs_you`. That freeze is what makes hits
feel heavy, and it's also the window where you can cancel into a special.

**Priority and trades:** if both players hit each other on the same frame, the stronger attack wins (heavy beats
medium beats light, with two special classes above heavy). Equal strengths trade: both hits land, and both get the
bigger hit stop. Two throws on the same frame are settled by whether the frame counter is odd or even.

**Blocking:** the attack's guard bits say how it can be blocked (standing, crouching, in the air). Blocked hits do
chip damage (damage divided by 4, 8 or 16, at least 1), and if chip would KO, the block fails.

**Parrying** (in SF3, "blocking"): tapping forward (or down for a low attack) just before a hit. The parry inputs
are command slots like the specials. A successful parry puts you back in neutral instantly with a short freeze you
can act out of, and freezes the attacker for 16 to 20 frames. You also get score and Super Art gauge.

### Health and gauges

- **Health:** every bar is the same length (160 points). Characters differ in durability instead: a tougher
  character loses fewer points per hit. The red "recent damage" part of the bar drains a little each frame.
- **Stun:** each hit adds to a stun meter that slowly recovers. Fill it and you're dizzy for a random time,
  shortened by mashing (the input code keeps a "mash score" for exactly this).
- **Super Art gauge:** filled from a per-character table with four columns: starting an attack, hitting, being
  blocked, parrying. Gains are boosted by 1.2x, and more in a single-round match.
- **Round timer:** starts at 99. How many frames each count lasts comes from the timer-speed setting (60, 53, 37
  or 29). It pauses during super freezes.

### Rounds, combos, score and grades

- **Round end:** time over gives the round to whoever has more health; a KO to whoever's standing; a double KO
  gives both a win. If that would decide the match, or health is equal at time over, the round goes to the
  **judges**, who compare each player's grade for the round.
- **Combos** are counted on the defender. A combo stays alive while the defender is in a damage, thrown or dizzy
  state, so "it was a combo" means "they never got control back".
- **Score** comes from hits, combos (priced from a table), parries and bonuses, capped at 99,999,900.
- **Grades** are 3rd Strike's report card. The game logs dozens of events (clean hits, guards, parries, reversals,
  throws, taunts, repeated moves) and builds four totals: offence, defence, technique and extra. The sum maps onto
  a threshold table to give the grade letter at the end of each fight. The final grade adds a score bonus.

---

## Tables: how the game is really built

If you read one section, read this one. The code in this game is mostly *engines*: small routines that walk data.
The characters, moves, animations, hit boxes and projectiles are all tables, and tables point at other tables. A
designer could change how a move works, what it looks like, or how fast a fireball flies by editing numbers,
without touching code. That's also why the same code runs all 20 characters.

The lifecycle of a typical lookup:

1. **Pick a set.** When a fighter is set up, `set_char_base_data` reads a row of `char_init_data` for that
   character and fills a dozen pointers in the `WORK`: animation tables, hit-box tables, attack tables. From then on
   the code only ever goes through those pointers, never the character's name.
2. **Pick a row.** Gameplay code computes a small index (which move, which strength, which frame) and looks it up
   in one of those tables.
3. **Follow the pointer.** That row often holds another pointer or index into the next table.
4. **Copy what you need.** At the end, the values are copied into the object's struct, so the rest of the frame
   reads plain fields.

### Worked example: Ryu throws a fireball

You press down, down-forward, forward and light punch. Here's every table it goes through.

**1. The motion.** `pl_CMD[2]` (Ryu is fighter 2) points at his 56 command slots. Slot 29 is `p2_cmd_29` (Capcom number
the command tables by fighter, and Ryu is fighter 2), the quarter-circle above. The three lever steps match, and `waza_flag[29]` is set to 12.

**2. The button.** While standing, `check_special_attack` loops over the ground-special slots 28-37:

```c
for (i = CMD_SP_GROUND; i < CMD_SA_AIR; i++) {        /* slots 28-37 */
    if (wk->cp->waza_flag[i] == -1) continue;            /* motion not done */
    ...
    cusw = conpane[wk->cp->btix[i] & CMD_BT_INDEX];      /* the button word to look at */
    for (j = 3; j >= 0; j--) {                           /* EX, heavy, medium, light */
        exsw = cusw & cmdshot_conv_tbl[wk->cp->exdt[i][j]];
        ...
        wk->as = &asstbl_sa_ground[wk->player_number][i - CMD_SA_GROUND][j].as;
        hissatsu_setup_union(wk, wk->cp->waza_r[i][j]);
```

- `btix & CMD_BT_INDEX` (0xFF) picks the `sw_chg` word, so pressing *or* releasing the button counts.
- It checks EX first, then heavy, medium, light, so pressing two punches gets you EX, not light.
- Flag `CMD_BT_SHELL` (0x800) in `btix` means "only one at a time": `shell_live_check` looks through Ryu's live projectiles for
  one from move 29, and if there is one, nothing happens.
- `asstbl_sa_ground` gives the animation number for this strength (24 for light), and `waza_r` gives the attack
  routine (16). `hissatsu_setup_union` sets `routine_no[1] = 4` (attacking) and `routine_no[2] = 16`.

**3. The routine.** Still this frame, `Player_attack` sees `routine_no[2] > 15`, so it's a special:
`plxx_extra_attack_table[2]` (Ryu's specials) → `pl02_exatt_table[0]` → `Att_HADOUKEN`. Its first step calls
`set_char_move_init(wk, 5, 24)`: table 5 of Ryu's `char_table` is `ryu_saca` (special-move animations), entry 24 is
`ryu_saca_024`.

**4. The animation.**

```c
L6(2, 0,   0, 0,0,0,0, 0x0EA0, 0, 74, 0, 0,  0,  0, 0, ...),   /* wind-up                    */
L6(2, 0,   0, 0,0,0,0, 0x0EAC, 0, 74, 0, 0,  0,  0, 0, ...),
L6(3, 0,   0, 0,0,0,0, 0x0EA1, 0, 74, 0, 0,  0,  0, 0, ...),
L6(2, 0, 525, 0,0,0,0, 0x0EA2, 0, 74, 0, 0,  0, 31, 1, ...),   /* sound; open the super window */
L6(1, 0,   0, 0,0,0,0, 0x0EA3, 0, 75, 0, 0, 64,  2, 0, ...),   /* effect 2: spawn the fireball */
L6(1, 0, 320, 0,0,0,0, 0x0EA4, 0, 75, 0, 0, 64, 21, 0, ...),
```

Nine frames of wind-up. On line 4, effect 31 arms the super-cancel flag, so the `cancel` value 64 on the next lines
means "you may cancel into a Super Art here". On line 5, `effect = 2` runs `effinitjptbl[2]`, which is
`effect_13_init`: the fireball is born on this exact frame. Ryu's own `att` is 0 on every line, so his body never
hits anything. The medium, heavy and EX versions have their own wind-ups, then jump into this script's tail, so all
four recover the same way.

**5. The fireball.** `effect_13_init` grabs a free effect slot, records it in Ryu's `shell_ix` (that's what the
one-at-a-time check looks at), copies his facing, position and colour, and points the object at
`tama_data[eftype]`:

```c
{ 4, 29, 0, 0x10, 0, 1, 0, 1, 2, 3, 4, 11, 12, 0, 0, 1, 384, 999, -64, 66, 0, 0 },
```

That row holds the object type (4, "projectile"), which move made it (29), which flight script and which end
scripts to use, which movement record, its power (384), its lifetime (999 frames), and where to appear relative to
Ryu's hand (-64, 66).

**6. Flight.** On its first frame, the fireball runs `set_char_base_data` too, with the shared projectile set
`char_init_data[11]`. So a fireball has animation, hit-box and attack tables just like a fighter. Its movement
record `ef13_movexy_table[0]` gives a speed of 1152 in 1/256 pixels: 4.5 pixels a frame for light, 5.625 for
medium, 6.75 for heavy. Each frame it moves, steps its animation (a loop of one-frame sprites), checks its lifetime
and whether it's left the screen, and queues itself for hit checking.

**7. The hit.** `attack_hit_check` finds the fireball's attack box overlapping the opponent. Projectiles aren't
allowed to hit their owner, and two projectiles can hit each other (each has type 4). On the hit:

- the opponent goes into the damage routine, or blocks, or parries;
- the fireball takes 256 off its own power. A normal fireball (384) drops below the line and plays its end script.
  The EX one (640) survives one hit and comes round for another, which is why EX hadoken hits twice;
- when it's gone, it clears itself from Ryu's `shell_ix`, and he can throw another.

The whole chain, in one line:

```
pl_CMD -> p2_cmd_29 -> waza_flag[29] -> btix/exdt -> asstbl_sa_ground -> plxx_extra_attack_table
-> pl02_exatt_table -> char_table[5] (ryu_saca) -> ryu_saca_024 -> effinitjptbl[2] -> tama_data
-> char_init_data[11] -> ef13 scripts, boxes, movement -> hit queue -> attack_hit_check
```

Every arrow is an index or a pointer. None of it is Ryu-specific code. Ken's fireball goes through exactly the same
routines with different numbers (his spawn line asks for `eftype` 40, a different `tama_data` row).

---

## Where to look

| You want | Start at |
|---|---|
| boot | `src/tasksw.src` `reset_entry`, `src/boot_task.c`, `src/mode_init.c` |
| the task switcher | `src/Entry.c` `Game_Task`, `src/tasksw.src` |
| the vblank | `src/intr.src` `_vblank_frame_dispatch` |
| scenes | `src/Game_Main.c` |
| coins and credits | `src/coin_sw.c`, `src/entry_2.c` |
| input to moves | `src/cmd_main_2.c`, `data/cmd_data.c`, `src/PLS03.c` |
| fighter states | `src/PLMAIN.c`, `src/PLNORMAL.c`, `src/PLPAT*.c`, `src/PLPDM.c` |
| animation scripts | `src/CHARMOVE.c`, `include/charscr.h`, `data/<fighter>_char.c` |
| hit boxes and hits | `src/HITCHECK.c`, `src/HIT*.c`, `data/<fighter>_hitbox.c` / `_attbox.c` / `_attr.c` |
| fireballs | `src/EFF13.c`, `data/EFF13_tbl.c` |
| damage, gauges | `src/pow_pow.c`, `src/PLSGAUGE.c`, `src/VITAL.c` |
| sprites | `src/aboutspr.c`, `src/spr_pool.c` |
| stages | `src/tate00.c`, `src/bg000.c`, `src/bg*.c` |
| attract mode | `src/demo00.c`, `src/demo01.c`, `src/demo02_code.c`, `src/end_main.c` |
| select | `src/sel_pl.c`, `src/next_cpu.c`, `src/EM_Cand.c` |
| AI | `src/Com_Pl.c`, `src/Com_Sub.c`, `src/SHELL*.c` (how the CPU deals with fireballs) |
| grades | `src/Grade.c` |
