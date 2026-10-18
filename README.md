# Street Fighter III 3rd Strike - CPS3 program source

**AI Disclosure**:
Yes, this used Claude, decompiling compilers is thirsty work.
It also used the hard manual work from https://github.com/crowded-street/3s-decomp which was hand built, and I have discussed that fact with them with approval.
The PS2 Debug disk of the Anniversary provided the layout, and names of most of what is in here and the 3s-decomp, and the names of the files here are what Capcom named their files, so blame them for Eff18.c etc.

It has been in the works for a number of months / years, and relies on the work of collaborators who know 3rd Strike inside out. 

Right, back to it.

C and SH-2 assembler source for the CPS3 program ROM of *Street Fighter III 3rd Strike: Fight for the Future*
(sfiii3nr1), built with the original Hitachi toolchain (SHC 5.0, asmsh, lnk 6.0, rof2bin). PS2 was used as a reference only, it is 100% Arcade logic and code.

The build is a byte-for-byte copy of the arcade program: every routine compiles from this C and assembler source
to the arcade's exact bytes. `build/prog.bin` has the arcade program's SHA-1, 7340968c4b2aba9496fa63be7a5c183205ff1dae,
and the eight program SIMM chips written into `build/sfiii3nr1.zip` are the original ROM's:

    sfiii3-simm1.0  crc 66e66235  sha1 0a98038721d176458d4f85dbd76c5edb93a65322
    sfiii3-simm1.1  crc 186e8c5f  sha1 a63040201a660b56217a8cbab32f5c2c466ee5dd
    sfiii3-simm1.2  crc bce18cab  sha1 a5c28063d98c22403756fc926a20631456fb7dcc
    sfiii3-simm1.3  crc 129dc2c9  sha1 c1e634d94b1c8f7f02a47703622de5cab3d0da3f
    sfiii3-simm2.0  crc 06eb969e  sha1 d89f6a6585b76692d57d337f0f8186398fb056da
    sfiii3-simm2.1  crc e7039f82  sha1 8e81e66b5a4f45ae14b070a491bde47a6a74499f
    sfiii3-simm2.2  crc 645c96f7  sha1 06d5a54874d4bf100b776131ec9060da209ad037
    sfiii3-simm2.3  crc 610efab1  sha1 bbc21ed6ff6220ff6017a3f02ebd9a341fbc9040

## Building

Needs Windows (the tools in `bin/` are Win32 programs) and Python 3.

1. Put your `sfiii3nr1.zip` in `rom/`.
2. Run `build.bat` (or `make`).

The build reads the graphics pattern tables from the ROM (they are not in this source), compiles and links the
program, and writes:

- `build/prog.bin` - the program image, 06000000-06FFFFFF
- `build/sfiii3nr1.zip` - your ROM set with the two program SIMMs replaced

`build/prog.bin` should match the SHA-1 in `tools/prog.sha1`, the arcade program's; the build prints whether it does.

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

The rebuilt SHC 5.0 Release 26 carries forty-four rules. None of them tests for a function's name or address, but
several have been seen in only one routine so far and rest on that single example. They reproduce observed code-generation
differences and include general optimizations verified across the ROM; these tests do not establish the historical
compiler's implementation:

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
- constants passed to calls count when deciding which values to keep in a register, inside loops too;
- `sts macl` is never scheduled ahead of the multiply it reads (a Release 26 scheduling fault), so array indexing
  can be written plainly;
- a branch is not threaded through a label that merging identical code created;
- a narrow value multiplied by a 16-bit constant uses `mul.l`, not `muls.w`, and a `short` is extended
  (`exts.w`) before that multiply;
- an integer cast of a table's name, `(u32)table`, is loaded again at each use rather than kept across calls;
- `f(&p->first)`, with `first` at offset 0, counts as passing `p`, so `p` can stay in its argument register;
- an expression several branches compute is computed again at each use when the first of them can't share its
  value, and so is each use a call or store cuts off from the first: only the uses reached from the first share its value;
- after a multiply the multiplier counts as busy for one instruction, not two, so `sts macl` can follow the next load;
  and that one instruction is the first that is ready, in either half of a long word (Release 26 keeps memory
  accesses to the first half there too, so it would take a literal load ahead of a register move);
- a load through a pointer and a later separate `add` to the pointer stay apart (Release 26 folds them into a
  post-increment load, `mov.w @r5+,r0`); the arcade has post-increments only where the source has `*p++`;
  likewise an `add` of minus the size to a pointer and a store through it stay apart (Release 26 folds them into
  a pre-decrement store), so `*--p = x` is `mov.l r1,@-r4` only while `p` is used again;
- a `char` cast of a loop counter's multiple, `(char)(i * 6)`, still counts as a multiple of the counter, so the
  value steps by 6 on each pass instead of being multiplied again (a cast to `short` is still recomputed, as in the arcade);
- a structure copied in a loop that counts down, `a[i] = a[i - 1]`, is copied first and its pointers are stepped
  after the copy (Release 26 makes the destination a pre-decrement access, which a block move can't use, so the
  pointer starts one element further on and is stepped before each copy);
- when the start of a loop's counter has been folded into the start of a stepping pointer (`for (i = 1; ...)`
  over 16-byte rows starts at `16 + base`), the constant stays in front: `mov #16,r1`, `add r5,r1` (Release 26
  moves it behind the base, `mov r5,r1`, `add #16,r1`, whenever a later pass looks at the sum again). Only one
  routine shows this, `debug_hit_a_judgement_build_table`;
- in the files compiled without optimization, a load or store of a local variable counts as 4 bytes, not 6, when
  the compiler decides where a literal pool goes, so those pools come later;
- a `for` or `while` loop is entered by a jump to its test at the bottom (Release 26, asked for speed, puts a copy
  of the test in front of nearly every loop instead); only a loop with no loop inside it, whose test compares two
  local variables or constants, gets the copy (as does a loop whose test is a floating-point comparison);
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
  sum is the address of a table or is already in r0, and for a fixed offset from an address the compiler itself
  keeps on the stack: the address is loaded and the offset added;
- an index used by several arrays in one statement stays in its own register, and each access takes its array's
  address into r0 or adds (Release 26 copies the index into r0 once and uses every array as a base);
- a zero that is added or subtracted (the index of `a[0]`) and the constant of a bit-and (`v & 3`) or of a
  bit-xor (`p->flag ^ 1`) count when a constant is weighed for a register, and read the register that holds it (Release 26 passes over every use that
  can be an immediate); so do a constant added to or subtracted from a local variable (`(ix + 1) & 1`) and the
  constant of `+=` and `-=`, while a constant added to a value just read from memory (`p->m + 1`) stays an immediate;
- a zero compared unsigned with a converted value (`i < n` with `unsigned i` and `int n`, in the test in front of
  a loop where `i` is still 0) is not an immediate: the SH has no unsigned compare with an immediate, so the zero
  is kept in a register and the compare reads that register (`cmp/hs r10,r4`); Release 26 goes by the type of the
  comparison itself, which is always a signed `int`, takes the zero for an immediate and copies its register
  first (`mov r4,r3`, `cmp/hs r10,r3`). Only one routine shows this, `strstr`;
- a mask by 0xff, `x & 0xFF` or `v &= 0xFF`, stays an `and` (Release 26 turns it into a cast, so the code
  extends with `extu.b`); `extu.b` comes from a cast or an `unsigned char`;
- a `char` or `short` value that is computed (not a variable or a value read from memory) and masked by a
  constant inside its width, `(s16)-p->x & 0x3FF`, is not extended first (`neg r0,r0`, `mov r0,r5`,
  `and r14,r5`), and the mask's constant is loaded before the value is computed (Release 26 extends the value
  with `exts.w` before the `and`); a value masked as it is stored, `((*cell++ = *tbl++) & 0x100) >> 8`, is
  still extended first, like a variable (`extu.w r1,r1` before `and r7,r1`). One routine shows each case,
  `update_all_disp_pos_ending` and `eff91_cell_data_set`;
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
  loads the address twice; a `char` or `short` variable used as such an index is taken the same way, unless its
  first use as an index in the function is the test of an `if`;
- an expression used in several blocks is shared even when it holds a temporary: with `table[ix]` read in
  several places the element address is computed once in front of its uses; Release 26 leaves such an
  expression alone, shares only the index and adds the table's address again at each use;
- a switch's comparison chain reuses the selector register r0 for a possible far jump to a case or default,
  where the selector is no longer needed, and records that use before restoring each case's register state.
  Release 26 uses r1, which also prevents preceding instructions that use r1 from filling some delay slots;
- byte and short integer sums reuse a constant already held in a register. Release 26 reserves that constant
  for a possible address displacement even though its address-folding pass excludes these narrow results.
  Wide integers and address calculations keep the original decision;
- an indexed word store loads its displacement before a constant OR when the prepared register operation
  leaves r0 untouched; calls, stack effects, volatile stores and r0 results keep the original order;
- a switch's jump table does not reset the short reach a word constant in front of it gave the next literal
  pool, so the pool behind the table comes sooner (Release 26 starts over with the long reach);
- when the place of a literal pool is worked out, a `return` in a function that saves one register and MACL
  is not counted as needing the exit's address as a literal (Release 26 counts MACH and MACL among the saved
  registers there, and with two or more a `return` is a jump that may need one);
- a compound assignment to a `char` or `short` local that is compared straight away, `if ((d += x) > 0x99)`,
  extends the result in the local's own register (Release 26 extends it into another register and compares
  that). Only one routine shows this, `abcd`;
- when an operator works out its right operand first, the registers its left operand worked in count as still
  holding their values until the operator's own instructions are done (Release 26 forgets them straight after
  the left operand), so in `G = A[i] + B[i][0];` the store to `G` goes through the register that held an
  earlier global's address;
- a quotient or remainder stored through the sum of two registers, `ixa[i] = tsc / table[i];`, has the value's
  registers chosen first, and the address is then added base first into the next free register (`mov r10,r2`,
  `add r7,r2`, ..., `mov.w r0,@r2`); Release 26 chooses the address register first (`mov r7,r3`, `add r10,r3`);
- when a conditional expression is assigned to a register variable, `msg = (n < 2) ? &one : &many;`, the
  variable's register is not offered to the test, so the tested value goes where the scratch registers are
  chosen (`cmp/ge #2` through r0); Release 26 loads the tested value into the variable's register. Only one
  routine shows this, `credit_display_render`.

The four changed stages (`shcmdl.exe`, `shcgen.exe`, `shcpep.exe` and `shcasm.exe`) are rebuilt from a C
decompilation of the originals (source: https://github.com/gibletto/shc-5r26-decomp-sf3), and each rule is a
setting in that source (forty-two settings for the forty-four rules: the switch rule and the return rule have two each, the `char` cast rule, the structure copy rule and the pointer start rule share `MDL_IV`, the two mask rules share `MDL_MASK_AND`, and the unsigned zero rule shares `MDL_IMM_REG` with the rule for constants that are added, masked or xored). With every setting at 0 they give the same output as Release 26. Setting `SWITCH_ARCADE_BRANCH`,
`SWITCH_ARCADE_JUMP`, `XJUMP_OFF`, `PEP_R0_FORGET`, `SLOT_NO_STACK`, `PEP_NO_THREAD`, `GEN_TST_R0`, `GEN_MUL_L`,
`MDL_ARG_CONST`, `MDL_CAST_CSE`, `MDL_ARG_CAST`, `MDL_GCSE`, `ASM_MULWAIT`, `GEN_CHAIN_SCRATCH_R0`, `GEN_NARROW_CONST`, `GEN_OR_INDEX_EARLY`, `PEP_AUTOINC`, `MDL_IV`, `GEN_POOL_MOVLOC`, `MDL_LOOP_INV`, `GEN_RELOAD`, `GEN_EVICT_ORDER`, `MDL_CAST_MUL`, `MDL_MUL_CONST`, `PEP_RET_R0`, `GEN_MEM_INDEX`, `GEN_R0VAR`, `MDL_IMM_REG`, `MDL_MASK_AND`, `MDL_IV_BASE`, `MDL_IV_TEMP`, `GEN_JUMP_TEMP`, `MDL_TEST_REPLACE`, `MDL_MUL_ONE`, `MDL_TEMP_EXPR`, `PEP_CASE_WORD`, `PEP_RET_MAC`, `GEN_NARROW_NORMALIZE`, `GEN_RIGHT_FIRST_DROP`, `GEN_STORE_INDEX`, `GEN_COND_PREF` and `ASM_SPECREG` to 0 gives Release 26's behaviour back. The
original files are in `bin/original`.

With the changes, all 10,066 C routines compile to the arcade's exact bytes (with the original Release 26, 3,782
compile to its instructions and 1,883 to its exact bytes), and the linked `build/prog.bin` has the arcade program's
SHA-1. Because the program is identical to the arcade's, Fightcade replays and FBNeo savestates play on the built
ROM unchanged.

## Thanks

Thanks to the 3sx Team and Artem for the 3s-decomp, which helped recover a large amount of this code style, and to
DrewDos for his matching work and help.

## License

GNU Affero General Public License v3.0 (`LICENSE`): parts of the source come from the 3s-decomp, which is AGPL-3.0.
`NOTICE.md` lists what the license does not cover.
