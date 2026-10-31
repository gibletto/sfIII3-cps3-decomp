# Street Fighter III 3rd Strike - CPS3 program source

**AI Disclosure**:
Yes, this used Claude, decompiling compilers is thirsty work.
It also used the hard manual work from https://github.com/crowded-street/3s-decomp which was hand built, and I have discussed that fact with them with approval.
The PS2 Debug disk of the Anniversary provided the layout, and names of most of what is in here and the 3s-decomp, and the names of the files here are what Capcom named their files, so blame them for Eff18.c etc.

It has been in the works for a number of months / years, and relies on the work of collaborators who know 3rd Strike inside out. 

Right, back to it.

## What this is

This is the program of the arcade game *Street Fighter III 3rd Strike: Fight for the Future* (sfiii3nr1), turned
back into source code. It is a decompilation: the machine code in the CPS3 program ROM has been rewritten as C and
as SH-2 assembler (the SH-2 is the arcade board's CPU), so people can read it and change it. PS2 was used as a
reference only, it is 100% Arcade logic and code.

It is also a byte-for-byte match. It builds with the original toolchain (Hitachi's SHC 5.0, asmsh 4.0 and lnk 6.0, and SEGA's rof2bin 2.51):
the compiler turns the C into machine code, the assembler does the same for the assembler files, and the linker
joins the pieces into one program. Every routine comes out as the arcade's exact bytes. `build/prog.bin` has the
arcade program's SHA-1 (a fingerprint of the whole file), 7340968c4b2aba9496fa63be7a5c183205ff1dae, and the eight
program SIMM chips written into `build/sfiii3nr1.zip` are the original ROM's:

    sfiii3-simm1.0  crc 66e66235  sha1 0a98038721d176458d4f85dbd76c5edb93a65322
    sfiii3-simm1.1  crc 186e8c5f  sha1 a63040201a660b56217a8cbab32f5c2c466ee5dd
    sfiii3-simm1.2  crc bce18cab  sha1 a5c28063d98c22403756fc926a20631456fb7dcc
    sfiii3-simm1.3  crc 129dc2c9  sha1 c1e634d94b1c8f7f02a47703622de5cab3d0da3f
    sfiii3-simm2.0  crc 06eb969e  sha1 d89f6a6585b76692d57d337f0f8186398fb056da
    sfiii3-simm2.1  crc e7039f82  sha1 8e81e66b5a4f45ae14b070a491bde47a6a74499f
    sfiii3-simm2.2  crc 645c96f7  sha1 06d5a54874d4bf100b776131ec9060da209ad037
    sfiii3-simm2.3  crc 610efab1  sha1 bbc21ed6ff6220ff6017a3f02ebd9a341fbc9040

For a tour of how the game itself works (the frame loop, inputs, special moves, hit boxes, damage), read
`docs/HOW_THE_GAME_WORKS.md`.

## Building

You need Windows (the tools in `bin/` are Win32 programs), Python 3 and your own ROM set.

1. Put your `sfiii3nr1.zip` in `rom/`.
2. Run `build.bat` (or `make`).

The graphics pattern tables are not in this source, so the build reads them from your ROM. Then it compiles and
links the program, and writes:

- `build/prog.bin` - the program image, 06000000-06FFFFFF
- `build/sfiii3nr1.zip` - your ROM set with the two program SIMMs (the eight chips above) replaced

`build/prog.bin` should match the SHA-1 in `tools/prog.sha1`, the arcade program's; the build prints whether it does.
If it doesn't, the build still writes both files, then stops with BUILD FAILED.

To run a new build in MAME, use an empty `-nvram_directory`. MAME keeps the program SIMMs' flash memory in nvram
and loads it over the ROM files, so an old nvram would run the old program instead of your build.

## Layout

    src/      game code (C, and SH-2 assembler in .src files)
    data/     game tables
    include/  headers
    lib/      the compiler's run-time routines (its built-in helpers), as linked into the program
    bin/      Hitachi SHC toolchain (four stages rebuilt, see Compiler; the originals are in bin/original)
    docs/     HOW_THE_GAME_WORKS.md: a tour of the game's code
    sf3.sub   link order and section addresses
    functions.tsv  every routine of the arcade program: arcade address, size, name, file
    tools/    cps3rom.py: reads the ROM set, writes the new one

## Compiler

Two versions of the same compiler can turn the same C into different machine code. So to match the arcade's bytes,
the code has to go through a compiler that makes the same choices as the one Capcom used.

A sibling of the compiler used by Capcom was found: SHC 5.0 Release 26 (SHC 5.0r26). It was decompiled and tested
to find out why its code came out the way it did. Most of the differences found were simply optimizations that
were not made by the newer version of the compiler, and rules were found that can be switched on to fit the code
better:

- Most rules are simple choices that, when enabled, worked for large swathes of the code, and could be determined to
  be real changes made to a later version of the compiler.
- Some are simplified rules about register choice (which of the CPU's working slots holds a value) that better
  suit the CPS3 hardware.
- A small handful only have limited use, but were made as plausible decisions a compiler could make.

There could still be source choices that would make some of this compiler work unnecessary if found, or compiler
choices that would be better if the real or simpler source were found. These would mostly help explain the
instructions the compiler emits, rather than make large sweeping changes. For example, a DEBUG flag that was
compiled out, where the source collapses to something like `if(0) { // do work}`, might have been an unknown
DEFINE. Without a source leak this might never be known.

The rebuilt SHC 5.0 Release 26 carries forty-four rules. None of them tests for a function's name or address, but
several have been seen in only one routine so far and rest on that single example. They reproduce observed
code-generation differences, and include general optimizations verified across the ROM.

[Link to the decompiled compiler](https://github.com/gibletto/shc-5r26-decomp-sf3/blob/main/SF3.md)

With the changes, all 10,066 C routines compile to the arcade's exact bytes, and the linked `build/prog.bin` has the
arcade program's SHA-1. (With the original Release 26, 3,782 compile to its instructions and 1,883 to its exact
bytes.) Because the program is identical to the arcade's, Fightcade replays and FBNeo savestates play on the built
ROM unchanged.

## Contributing

As this is an exact byte-match, every contribution must keep the match. Contributions should either:

- improve or explain the code, or
- improve or remove compiler flags, and come with a PR to the compiler decomp project too.

A "fake" match is source that builds the right bytes but is unlikely to be what Capcom wrote. The number of them
is low; any changes should lower them or explain them, still with evidence or better code.

## Thanks

Thanks to the 3sx Team and Artem for the 3s-decomp, which helped recover a large amount of this code style, and to
DrewDos for his matching work and help.

Thanks also to Dominic Evans (X: [@oldmanuk](https://x.com/oldmanuk)) for clean-up suggestions.

## License

GNU Affero General Public License v3.0 (`LICENSE`): parts of the source come from the 3s-decomp, which is AGPL-3.0.
`NOTICE.md` lists what the license does not cover.
