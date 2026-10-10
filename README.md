# Street Fighter III 3rd Strike - CPS3 program source

**AI Disclosure**:
Yes, this used Claude, decompiling compilers is thirsty work.
It also used the hard manual work from https://github.com/crowded-street/3s-decomp which was hand built, and I have discussed that fact with them with approval.
The PS2 Debug disk of the Anniversary provided the layout, and names of most of what is in here and the 3s-decomp, and the names of the files here are what Capcom named their files, so blame them for Eff18.c etc.

It has been in the works for a number of months / years, and relies on the work of collaborators who know 3rd Strike inside out. 

Right, back to it.

C and SH-2 assembler source for the CPS3 program ROM of *Street Fighter III 3rd Strike: Fight for the Future*
(sfiii3nr1), built with the original Hitachi toolchain (SHC 5.0, asmsh, lnk 6.0, rof2bin). PS2 was used as a reference only, it is 100% Arcade logic and code.

The build is a working program, not a byte-for-byte copy of the arcade ROM as matching is in the final stages: code and data are laid out by the
linker from this source.

## Building

Needs Windows (the tools in `bin/` are Win32 programs) and Python 3.

1. Put your `sfiii3nr1.zip` in `rom/`.
2. Run `build.bat` (or `make`).

The build reads the graphics pattern tables from the ROM (they are not in this source), compiles and links the
program, and writes:

- `build/prog.bin` - the program image, 06000000-06FFFFFF
- `build/sfiii3nr1.zip` - your ROM set with the two program SIMMs replaced

`build/prog.bin` should match the SHA-1 in `tools/prog.sha1`; the build prints whether it does.

When running a new build in MAME, use an empty `-nvram_directory`: MAME keeps the program SIMMs' flash in nvram
and loads it over the ROM files.

## Layout

    src/      game code (C, and SH-2 assembler in .src files)
    data/     game tables
    include/  headers
    lib/      the compiler's run-time routines, as linked into the program
    bin/      Hitachi SHC toolchain (four stages rebuilt, see below; the originals are in bin/original)
    sf3.sub   link order and section addresses
    functions.tsv  every routine of the arcade program: arcade address, size, name, file
    tools/    cps3rom.py: reads the ROM set, writes the new one

## Compiler

The compiler is SHC 5.0 Release 26 with thirty-two changes, each one a rule the arcade's own compiler visibly follows
throughout the ROM but Release 26 doesn't:

- a switch case is tested with `bt case` / `bra default` (Release 26 folds it into `bf default`), and a jump whose
  target has become the next block is kept as a `bra` to the next instruction: the jump to a case or default
  label, the jump over an else arm that was merged with a later identical block, the jump in front of
  `else return;` (Release 26 deletes every such jump; only the one a then arm makes over `else break;` still goes);
- two returns share the instructions they end with only as far back as those leave r0 alone: the store or call
  in front of a plain `return;`, never the `mov #0,r0` of `return 0;` (Release 26 shares every instruction they
  end with), and an instruction that uses r0 does not fill the delay slot of the jump to the shared code; inside
  a `switch`, a return whose whole block would be shared keeps its own copy; and once returns were shared the
  function keeps its epilogue and `rts`, even when every path now ends in a tail call; it keeps them too when
  the only jump to them was in code that could not be reached and was removed (`if (c) f(); else g(); break;`
  at the end of a function);
- a constant loaded into r0 is loaded again after a conditional branch (Release 26 carries it across);
- a stack load or store never fills a branch delay slot;
- a value that is only tested takes the lowest free register (Release 26 starts from r3);
- constants passed to calls count when deciding which values to keep in a register;
- `sts macl` is never scheduled ahead of the multiply it reads (a Release 26 scheduling fault), so array indexing
  can be written plainly;
- a branch is not threaded through a label that merging identical code created;
- a narrow value multiplied by a 16-bit constant uses `mul.l`, not `muls.w`, and a `short` is extended
  (`exts.w`) before that multiply;
- an integer cast of a table's name, `(u32)table`, is loaded again at each use rather than kept across calls;
- `f(&p->first)`, with `first` at offset 0, counts as passing `p`, so `p` can stay in its argument register;
- a global variable is loaded again at each use, not read from a copy an earlier use kept in a register or on the stack;
  the same goes for an expression several branches compute, when the first of them can't share its value, and
  for the uses a call or store cuts off from the first: only the uses reached from the first share its value;
- after a multiply the multiplier counts as busy for one instruction, not two, so `sts macl` can follow the next load;
- a switch's compare-and-branch jumps leave r1 free, so a value live into the cases can move into it and r13/r14 is not saved;
- a load through a pointer and a later separate `add` to the pointer stay apart (Release 26 folds them into a
  post-increment load, `mov.w @r5+,r0`); the arcade has post-increments only where the source has `*p++`;
  likewise an `add` of minus the size to a pointer and a store through it stay apart (Release 26 folds them into
  a pre-decrement store), so `*--p = x` is `mov.l r1,@-r4` only while `p` is used again;
- a `char` cast of a loop counter's multiple, `(char)(i * 6)`, still counts as a multiple of the counter, so the
  value steps by 6 on each pass instead of being multiplied again (a cast to `short` is still recomputed, as in the arcade);
- in the files compiled without optimization, a load or store of a local variable counts as 4 bytes, not 6, when
  the compiler decides where a literal pool goes, so those pools come later;
- a `for` or `while` loop is entered by a jump to its test at the bottom (Release 26, asked for speed, puts a copy
  of the test in front of nearly every loop instead); only a loop with no loop inside it, whose test compares two
  local variables or constants, gets the copy;
- the last use of a variable kept on the stack reads it from the stack again, even straight after the store
  (Release 26 takes it from the register the value was computed in); earlier uses still take the register;
- once an array's address is loaded, the scratch register that held an earlier address or constant counts as
  free again (Release 26 goes on avoiding it), so the next value is loaded into it;
- a `short` or `char` index whose first use is scaled (`shorts[ix]`) is extended again at each `chars[ix]`
  (Release 26 extends it once for the byte arrays and keeps that copy in a register across branches);
- a multiply reads a constant that is already in a register: a `char` or `short` multiply takes it from there
  (`muls.w r12,r3`, where Release 26 shifts), and the 16-bit constant of an `int` multiply of a `char` or `short`
  counts like any other, so `s * 100` used three times keeps 100 in a register (Release 26 loads it at each multiply);
- when an address is the sum of a pointer still in memory (a row of a table of pointers, `table[a]` in
  `table[a][b]`) and an index in a register, the pointer is loaded and added (`mov.l @(r0,r3),r3`, `add r3,r2`,
  `mov.l @r2,r1`); Release 26 loads it into r0 and indexes with it; the same holds when the other part of the
  sum is the address of a table or is already in r0;
- an index used by several arrays in one statement stays in its own register, and each access takes its array's
  address into r0 or adds (Release 26 copies the index into r0 once and uses every array as a base);
- a zero that is added or subtracted (the index of `a[0]`) and the constant of a bit-and (`v & 3`) count when a
  constant is weighed for a register, and read the register that holds it (Release 26 passes over every use that
  can be an immediate); so do a constant added to or subtracted from a local variable (`(ix + 1) & 1`) and the
  constant of `+=` and `-=`, while a constant added to a value just read from memory (`p->m + 1`) stays an immediate;
- a mask by 0xff, `x & 0xFF` or `v &= 0xFF`, stays an `and` (Release 26 turns it into a cast, so the code
  extends with `extu.b`); `extu.b` comes from a cast or an `unsigned char`;
- in a loop, the address of a member reached through a pointer, `p->a`, is not taken as fixed when stepping
  pointers are made, so for `p->a[i]` only `i * size` steps (Release 26 makes the element's address a pointer
  that steps by the element size);
- a value derived from the loop counter and used more than once (`i * 2`, or `&a[i]` used by two statements)
  gets a new stepping variable, and the shared copy is taken from it on each pass (`mov r4,r7`); Release 26
  steps the shared copy itself. An address that another argument of the same call takes again
  (`f(a[i].x, a[i].y)`) or that one test uses twice, and an address a later statement uses while the counter
  counts down, keep Release 26's choice, and the index of a `char` array is extended on each pass instead of stepped;
- the scratch register a `break` or `continue` picks for its jump is not counted as in use by the statement in
  front of it, so a value that is live there can still move into that register at the end of the function and
  r8-r14 need not be saved for it (Release 26 counts it);
- when every use of an `int` loop counter has become a stepping pointer, the counter is dropped and the loop's
  test compares one of the pointers with the end of the table (`cmp/hs r14,r4`); Release 26 holds the code for
  this but no option switches it on, so it keeps the counter beside the pointers;
- the index of a `char` array that is read from memory (`flags[p->id]`, `cols[src[i]]`) is the converted value
  itself, so `flags[p->id] &= 0x80` keeps the index in r0, loads the array's address once, reads through it
  indexed and copies it for the store; Release 26 takes the index for a second value, copies it out of r0 and
  loads the address twice;
- an expression used in several blocks is shared even when it holds a temporary: with `table[ix]` read in
  several places the element address is computed once in front of its uses; Release 26 leaves such an
  expression alone, shares only the index and adds the table's address again at each use.

The four changed stages (`shcmdl.exe`, `shcgen.exe`, `shcpep.exe` and `shcasm.exe`) are rebuilt from a C
decompilation of the originals (source: https://github.com/gibletto/shc-5r26-decomp-sf3), and each rule is a
setting in that source (thirty-four settings for the thirty-two rules: the switch rule and the return rule have two each). With every rule off they give the same output as Release 26. Setting `SWITCH_ARCADE_BRANCH`,
`SWITCH_ARCADE_JUMP`, `XJUMP_OFF`, `PEP_R0_FORGET`, `SLOT_NO_STACK`, `PEP_NO_THREAD`, `GEN_TST_R0`, `GEN_MUL_L`,
`MDL_ARG_CONST`, `MDL_CAST_CSE`, `MDL_ARG_CAST`, `MDL_GCSE`, `ASM_MULWAIT`, `GEN_CHAIN_JUMP`, `PEP_AUTOINC`, `MDL_IV`, `GEN_POOL_MOVLOC`, `MDL_LOOP_INV`, `GEN_RELOAD`, `GEN_EVICT_ORDER`, `MDL_CAST_MUL`, `MDL_MUL_CONST`, `PEP_RET_R0`, `GEN_MEM_INDEX`, `GEN_R0VAR`, `MDL_IMM_REG`, `MDL_MASK_AND`, `MDL_IV_BASE`, `MDL_IV_TEMP`, `GEN_JUMP_TEMP`, `MDL_TEST_REPLACE`, `MDL_MUL_ONE`, `MDL_TEMP_EXPR` and `ASM_SPECREG` to 0 gives Release 26's behaviour back. The
original files are in `bin/original`.

With the changes, 9,657 of the 10,066 C routines compile to the arcade's instructions (3,793 with the original
Release 26), and 9,478 to its exact bytes (1,876). Over 254 Fightcade replays compared with the original ROM,
254 keep identical game state throughout (218 before) and 254 identical slowdown (214).

## Fightcade replays

Fightcade replays can't be played on this build out of the box. A replay is an FBNeo savestate taken on the real
ROM plus the inputs for each frame. Work RAM and the ROM tables are at the same addresses in this build, but the
code isn't. The saved CPU state, task stacks and function pointers all point into arcade code, so loading the
savestate as is will crash.

You'd need a custom FBNeo build that can:

- run the replay on the original ROM and save a state once the scheduler (`Game_Task`) is idle, so no task is
  halfway through a function;
- load that state into this build with a patch applied (registers and RAM words), then carry on feeding the
  replay's inputs from that frame.

Making the patch is the fiddly part:

- `functions.tsv` gives each routine's arcade address and `sf3.map` gives where it ended up, so any code address
  in the state can be mapped by name.
- Restart the scheduler at `Game_Task` on its boot stack, and point each task's function slot at the new address.
- If a sleeping task's function is just a loop around its sleep call, restart it at its entry. Otherwise fix up
  its saved return address and whatever registers the new code expects to survive the call.
- Some words in the initialised data (the part copied from ROM at boot) still hold arcade code addresses. Swap
  those for the new ones. If anything else in RAM looks like a code address, check it by hand.

To compare the two runs, hash the game variables every logic frame (not every video frame) and treat code
addresses as zero, since they'll always differ. Expect the odd drift where the arcade drops a frame and this build
doesn't. The code doesn't take exactly the same cycles yet, so that's timing, not a logic bug.

## Thanks

Thanks to the 3sx Team and Artem for the 3s-decomp, which helped recover a large amount of this code style, and to
DrewDos for his matching work and help.
