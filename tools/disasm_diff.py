#!/usr/bin/env python3
"""Show ROM vs compiled instructions side by side. usage: disasm_diff.py <seg> <fn> <file.c>"""
import subprocess, sys, tempfile
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent))
import match

def dis(code: bytes) -> list[str]:
    with tempfile.TemporaryDirectory() as d:
        Path(d, "b").write_bytes(code)
        out = match.run("mips-linux-gnu-objdump", "-b", "binary", "-m", "mips:4300", "-EB", "-D", "-M", "no-aliases", d + "/b")
    return [l.split("\t", 2)[-1] if "\t" in l else l for l in out.splitlines() if l[:1] == " " and ":" in l]

seg, name, cfile = sys.argv[1], sys.argv[2], Path(sys.argv[3])
want, _ = match.original(seg, name)
got, masks = match.compiled(cfile, name, match.file_flags(cfile))
w, g = dis(want), dis(got)
for i in range(max(len(w), len(g))):
    a, b = (w[i] if i < len(w) else ""), (g[i] if i < len(g) else "")
    print(f"{i*4:04x} {'  ' if a == b else '!!'} {a:<40} | {b}")
