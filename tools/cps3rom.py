#!/usr/bin/env python3
"""Street Fighter III 3rd Strike (CPS3) program ROM tool.

    python tools/cps3rom.py extract <sfiii3nr1.zip> <cg.bin>
        Read the two program SIMMs (sfiii3-simm1.*, sfiii3-simm2.*) from the ROM set, decrypt them and write
        the graphics pattern directory and patterns (06800000-06E5E91F), which the build does not compile.

    python tools/cps3rom.py pack <sf3.bin> <cg.bin> <sfiii3nr1.zip> <out dir>
        Put the patterns into the linked image, write <out dir>/prog.bin (06000000-06FFFFFF), compare it
        with the expected image, and write <out dir>/sfiii3nr1.zip: the ROM set with the two program SIMMs
        replaced by the new program.

A program SIMM is four 2 MB chips, one byte lane each, encrypted with the CPS3 address mask (MAME's
cps3_state::cps3_mask, 3rd Strike keys).
"""
import hashlib, sys, zipfile
from pathlib import Path

CHIP = 0x200000
SIMM = 4 * CHIP
KEY1, KEY2 = 0xA55432B4, 0x0C129981
CG_START, CG_END = 0x06800000, 0x06E5E920
EXPECTED = Path(__file__).with_name("prog.sha1")


def rol16(v, n):
    v &= 0xFFFF
    return ((v << n) | (v >> (16 - n))) & 0xFFFF


def rotxor(val, x):
    res = (val + rol16(val, 2)) & 0xFFFF
    return (rol16(res, 4) ^ (res & (val ^ x))) & 0xFFFF


def mask(addr):
    addr ^= KEY1
    v = (addr & 0xFFFF) ^ 0xFFFF
    v = rotxor(v, KEY2 & 0xFFFF)
    v ^= ((addr >> 16) & 0xFFFF) ^ 0xFFFF
    v = rotxor(v, KEY2 >> 16)
    v ^= (addr & 0xFFFF) ^ (KEY2 & 0xFFFF)
    return (v | (v << 16)) & 0xFFFFFFFF


def read_simm(z, n, base):
    chips = [z.read(f"sfiii3-simm{n}.{i}") for i in range(4)]
    out = bytearray(SIMM)
    for i in range(CHIP):
        w = (chips[0][i] << 24 | chips[1][i] << 16 | chips[2][i] << 8 | chips[3][i]) ^ mask(base + i * 4)
        out[i * 4:i * 4 + 4] = w.to_bytes(4, "big")
    return out


def write_simm(flat, base):
    chips = [bytearray(CHIP) for _ in range(4)]
    for i in range(CHIP):
        w = int.from_bytes(flat[i * 4:i * 4 + 4], "big") ^ mask(base + i * 4)
        for c in range(4):
            chips[c][i] = (w >> (24 - 8 * c)) & 0xFF
    return [bytes(c) for c in chips]


def extract(rom, out):
    with zipfile.ZipFile(rom) as z:
        simm2 = read_simm(z, 2, 0x06800000)
    Path(out).parent.mkdir(parents=True, exist_ok=True)
    Path(out).write_bytes(simm2[:CG_END - CG_START])
    print(f"{out}: {CG_END - CG_START} bytes from {rom}")


def pack(image, cg, rom, outdir):
    prog = bytearray(Path(image).read_bytes())
    if len(prog) != 2 * SIMM:
        sys.exit(f"{image}: expected {2 * SIMM} bytes")
    prog[CG_START - 0x06000000:CG_END - 0x06000000] = Path(cg).read_bytes()
    out = Path(outdir); out.mkdir(parents=True, exist_ok=True)
    (out / "prog.bin").write_bytes(prog)
    sha1 = hashlib.sha1(prog).hexdigest()
    want = EXPECTED.read_text().split()[0] if EXPECTED.exists() else None
    print(f"prog.bin sha1 {sha1}: " + ("matches" if sha1 == want else f"DIFFERS from expected {want}"))
    new = {}
    for n, base in ((1, 0x06000000), (2, 0x06800000)):
        for i, chip in enumerate(write_simm(prog[(n - 1) * SIMM:n * SIMM], base)):
            new[f"sfiii3-simm{n}.{i}"] = chip
    with zipfile.ZipFile(rom) as src, zipfile.ZipFile(out / "sfiii3nr1.zip", "w", zipfile.ZIP_DEFLATED) as dst:
        for info in src.infolist():
            dst.writestr(info.filename, new.get(info.filename) or src.read(info.filename))
    print(f"{out / 'sfiii3nr1.zip'} written")
    return sha1 == want


if __name__ == "__main__":
    if len(sys.argv) == 4 and sys.argv[1] == "extract":
        extract(sys.argv[2], sys.argv[3])
    elif len(sys.argv) == 6 and sys.argv[1] == "pack":
        sys.exit(0 if pack(*sys.argv[2:]) else 1)
    else:
        sys.exit(__doc__)
