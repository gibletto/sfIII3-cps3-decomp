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

The compiler is SHC 5.0 Release 26 with sixteen changes, each one a rule the arcade's own compiler visibly follows
throughout the ROM but Release 26 doesn't:

- a switch case is tested with `bt case` / `bra default` (Release 26 folds it into `bf default`), and a jump to
  a case label that is also the next block is kept;
- functions keep a separate `rts` at each return (Release 26 merges identical returns; jumps and labels are still
  shared, as in the arcade);
- a constant loaded into r0 is loaded again after a conditional branch (Release 26 carries it across);
- a stack load or store never fills a branch delay slot;
- a value that is only tested takes the lowest free register (Release 26 starts from r3);
- constants passed to calls count when deciding which values to keep in a register;
- `sts macl` is never scheduled ahead of the multiply it reads (a Release 26 scheduling fault), so array indexing
  can be written plainly;
- a branch is not threaded through a label that merging identical code created;
- a narrow value multiplied by a 16-bit constant uses `mul.l`, not `muls.w`;
- an integer cast of a table's name, `(u32)table`, is loaded again at each use rather than kept across calls;
- `f(&p->first)`, with `first` at offset 0, counts as passing `p`, so `p` can stay in its argument register;
- a global variable is loaded again at each use, not read from a copy an earlier use kept in a register or on the stack;
- after a multiply the multiplier counts as busy for one instruction, not two, so `sts macl` can follow the next load;
- a switch's compare-and-branch jumps leave r1 free, so a value live into the cases can move into it and r13/r14 is not saved;
- a load through a pointer and a later separate `add` to the pointer stay apart (Release 26 folds them into a
  post-increment load, `mov.w @r5+,r0`); the arcade has post-increments only where the source has `*p++`;
- a `char` cast of a loop counter's multiple, `(char)(i * 6)`, still counts as a multiple of the counter, so the
  value steps by 6 on each pass instead of being multiplied again (a cast to `short` is still recomputed, as in the arcade).

The four changed stages (`shcmdl.exe`, `shcgen.exe`, `shcpep.exe` and `shcasm.exe`) are rebuilt from a C
decompilation of the originals (source: https://github.com/gibletto/shc-5r26-decomp-sf3), and each rule is a
setting in that source (seventeen settings for the sixteen rules: the switch rule has two). With every rule off they give the same output as Release 26. Setting `SWITCH_ARCADE_BRANCH`,
`SWITCH_ARCADE_JUMP`, `XJUMP_OFF`, `PEP_R0_FORGET`, `SLOT_NO_STACK`, `PEP_NO_THREAD`, `GEN_TST_R0`, `GEN_MUL_L`,
`MDL_ARG_CONST`, `MDL_CAST_CSE`, `MDL_ARG_CAST`, `MDL_GCSE`, `ASM_MULWAIT`, `GEN_CHAIN_JUMP`, `PEP_AUTOINC`, `MDL_IV` and `ASM_SPECREG` to 0 gives Release 26's behaviour back. The
original files are in `bin/original`.

With the changes, 8,623 of the 10,048 C routines compile to the arcade's instructions (3,684 with the original
Release 26), and 7,958 to its exact bytes (1,745). Over 254 Fightcade replays compared with the original ROM,
246 keep identical game state throughout (218 before) and 244 identical slowdown (214).

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
