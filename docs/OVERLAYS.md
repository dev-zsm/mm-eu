# Decompiling the overlays

Overlays (actors, scenes, menus) are small relocatable programs that the game loads on demand: `text | data | rodata |
header | relocations | footer`. They are linked at address 0, so their functions are read at `0x80000000 + offset`
(`func_80000000`, `func_8000009C`, ...). Two overlays can have functions of the same name; always give the overlay
with the function (`ovl0050` is the file with index 0050 of the ROM file table).

## Setup, once

1. `python3 tools/extract.py` extracts the files of the ROM into `extracted/`.
2. `python3 tools/overlays.py` finds the overlays and writes `config/overlays.txt`.
3. `python3 tools/overlay_split.py` disassembles every overlay into `asm/overlays/<index>/` and checks that the
   assembly rebuilds the file (a single overlay: `python3 tools/overlay_split.py 0050`).

## Writing and checking one function

The same loop as for `boot` and `code` (see [CONTRIBUTING.md](CONTRIBUTING.md) and `tools/AGENT_BRIEF.md`), with the
segment name `ovl<index>`:

```
tools/mm asm   ovl0050 func_8000009C                       original assembly
tools/mm m2c   ovl0050 func_8000009C                       first draft (often wrong)
tools/mm match ovl0050 func_8000009C src/overlays/0050/func_8000009C.c
tools/mm diff  ovl0050 func_8000009C src/overlays/0050/func_8000009C.c
```

- Write the file as `src/overlays/<index>/<function>.c`; unfinished attempts go to `src/overlays/<index>/wip/`.
- Calls into `boot` or `code` keep the address name of the callee (`func_8013F34C`) until names are registered for it.
- The match is checked per function only, with relocated fields masked, so a wrong callee or data address is not caught:
  the overlay build that links the relocated sections and checks the relocation table is not written yet (see the
  roadmap). A MATCH needs the exact size of the function.
- `make split` runs step 3 of the setup, and `make check` needs its output.
- The flags, `// COMPILER: ido53`, the idioms and the rules about sources are those of the other segments. Only the
  assembly of our ROM and the local tools are used.

## Order of work

Start with the smallest overlays: they match fastest and show the structure shared by many of them (initialisation,
update, draw functions). Then the large ones. Progress is added up over all the overlays in [PROGRESS.md](PROGRESS.md).

## Names

Overlay and function names come only from evidence, as for the other segments: they are registered in
`config/overlays.names.txt` (`<file index> <name>  # <evidence>`) once that file exists. Until then, folders and
functions keep their file index and address names.
