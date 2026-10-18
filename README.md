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

In order to complete a 100% match, a sibling of the compiler used by Capcom was found (SHC 5.0r26). It was decompiled and tested in order to find why code emitted made the choices it did. Most of the choices found were simply optimizations that were not made by the newer version of the compiler, and rules were found which could be toggled in order to better fit the code. These rules for the most part were simple choices that when enabled, worked for large swatches of the code and could be determined to be real changes made to a later version of the compiler. Some were simplified rules around register choice which better suited CPS3 hardware, and a small handful only had limited use cases, but were made as plausible decisions that could be made. However, there could still be source choices made that could render the compiler work obsolete if found, or compiler choices that would be better if the real or simpler source could be found. These source choices would mostly be used to better understand the instructions emitted, versus large sweeping changes. i.e.: A DEBUG flag which was compiled out, but the source collapses to something like `if(0) { // do work}`` which might have been an unknown DEFINE. Without a source leak this might never be known.

The rebuilt SHC 5.0 Release 26 carries forty-four rules. None of them tests for a function's name or address, but
several have been seen in only one routine so far and rest on that single example. They reproduce observed code-generation
differences and include general optimizations verified across the ROM;

[Link to the decompiled compiler](https://github.com/gibletto/shc-5r26-decomp-sf3/blob/main/SF3.md)

With the changes, all 10,066 C routines compile to the arcade's exact bytes (with the original Release 26, 3,782
compile to its instructions and 1,883 to its exact bytes), and the linked `build/prog.bin` has the arcade program's
SHA-1. Because the program is identical to the arcade's, Fightcade replays and FBNeo savestates play on the built
ROM unchanged.

## Contributing
As this is a exact byte-match, contributions should maintain a match while either improving / explaining code, or improve / remove compiler flags and come with a PR to the compiler decomp project also. The number of "fake" matches is low, and any changes should be to lower them / explain them still with evidence / better code.

## Thanks

Thanks to the 3sx Team and Artem for the 3s-decomp, which helped recover a large amount of this code style, and to
DrewDos for his matching work and help.

## License

GNU Affero General Public License v3.0 (`LICENSE`): parts of the source come from the 3s-decomp, which is AGPL-3.0.
`NOTICE.md` lists what the license does not cover.
