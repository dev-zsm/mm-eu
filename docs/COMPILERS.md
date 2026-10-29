# Compilers

The game was not built with a single compiler version. Two builds of the original SGI IDO compiler are used, both
fetched by `make setup` into `tools/vendor/` (not tracked):

| Compiler | Folder | Used for |
|---|---|---|
| IDO 7.1 | `tools/vendor/ido71` | everything, by default |
| IDO 5.3 | `tools/vendor/ido53` | the files marked `// COMPILER: ido53` (part of libultra, e.g. the controller / Controller Pak routines and `ldiv`), which only match with the older compiler |

If you ran `make setup` before IDO 5.3 was added, just run it again: it only downloads what is missing. To install IDO 5.3
by hand (from the project root, on Linux / WSL):

```
mkdir -p tools/vendor/ido53
curl -sL https://github.com/decompals/ido-static-recomp/releases/download/v1.2/ido-5.3-recomp-linux.tar.gz | tar -xz -C tools/vendor/ido53
```

IDO 7.1 is the same with `ido-7.1-recomp-linux.tar.gz` and `tools/vendor/ido71`. Check with
`ls tools/vendor/ido71/cc tools/vendor/ido53/cc`.

A source file picks its compiler and flags in its first lines:

```c
// FLAGS: -O2 -g0 -mips2        optional, first line: optimisation flags (default -O2 -g3 -mips2)
// COMPILER: ido53              optional, within the first three lines: build this file with IDO 5.3
```

Without the second line a file is built with IDO 7.1. `tools/match.py`, `tools/verify_src.py` and
`tools/build_seg.py` all read these two lines, so a file is compiled the same way by every tool. Never switch a file to
IDO 5.3 to make it match: use it only when the original really was built with it, which shows as a function that
matches with 5.3 and not with 7.1 (typically struct copies going through `$at`).
