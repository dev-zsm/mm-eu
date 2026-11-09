# Decompiling the overlays

Overlays (actors, scenes, menus) are small relocatable programs that the game loads on demand: `text | data | rodata |
header | relocations | footer`. They are linked at address 0, so their functions are read at `0x80000000 + offset`
(`func_80000000`, `func_8000009C`, ...). Two overlays can have functions of the same name; always give the overlay
with the function (`ovl0050` is the file with index 0050 of the ROM file table).

## Setup, once

1. `python3 tools/split/extract.py` extracts the files of the ROM into `extracted/`.
2. `python3 tools/split/overlays.py` finds the overlays and writes `config/overlays/list.txt`.
3. `python3 tools/split/overlay_split.py` disassembles every overlay into `asm/overlays/<index>/` and checks that the
   assembly rebuilds the file (a single overlay: `python3 tools/split/overlay_split.py 0050`).

## Writing and checking one function

The same loop as for `boot` and `code` (see [CONTRIBUTING.md](CONTRIBUTING.md) and `tools/agents/AGENT_BRIEF.md`), with the
segment name `ovl<index>`:

```
tools/mm asm   ovl0050 func_8000009C                       original assembly
tools/mm m2c   ovl0050 func_8000009C                       first draft (often wrong)
tools/mm match ovl0050 func_8000009C src/overlays/0050/func_8000009C.c
tools/mm diff  ovl0050 func_8000009C src/overlays/0050/func_8000009C.c
```

- Write the file as `src/overlays/<index>[_<name>]/<function>.c`; unfinished attempts go to `src/overlays/<index>[_<name>]/wip/`.
- Calls into `boot` or `code` keep the address name of the callee (`func_8013F34C`) until names are registered for it.
- The match is checked per function only, with relocated fields masked, so a wrong callee or data address is not caught:
  the overlay build that links the relocated sections and checks the relocation table is not written yet (see the
  roadmap). A MATCH needs the exact size of the function.
- `make split` runs step 3 of the setup, and `make check` needs its output.
- The flags, `// COMPILER: ido53` and the idioms are those of the other segments.

## Functions from the reference

`python3 tools/search/ref_import.py run overlays` compiles the reference sources of the overlays with this project's flags and keeps the
functions whose bytes are the ROM's (see [TOOLS.md](TOOLS.md)). The file of such a function includes the header of its reference file
(`include/generated/mm/`), which holds the context once; the function is defined under the address name of ours by an alias, and the
symbols it calls or reads are aliases to ours. Many of the functions of an actor are `static` in the reference: the tool removes that,
because IDO drops a static function that nobody calls in a file that holds only that function.

## What the check does and does not see

`tools/check/verify_src.py overlays` compares the bytes with the relocated fields masked, then where every call or data reference of the
code would link to against the ROM's. Inside an overlay the ROM holds the link-time value of such a field (`jal 0x008623DC`), which the
relocation table of the overlay corrects when it is loaded: those references are not compared (they are counted as "of unknown
address"). The ones towards the code and boot segments are.

## Jump tables (switch)

`match.py` does not see a jump table: it lives in the `.rodata` of the overlay, and its entries are link-time addresses that the relocation table
corrects at load time. A `case` moved to another value keeps the code bytes and changes only the table, so a `switch` can be reported `MATCH` with a
wrong table (checked: `case 11:` written `case 10:` in a matched function). What can be verified: every entry of the table is an `R_MIPS_32`
relocation against `.text` in our object, and its addend is the offset of the case label. The ROM's entry minus the link base of the overlay (the
base is the one for which every `jal` target inside the file is the start of a function, `tools/lib/hardjt.py link_base`) is the same offset.
`python3 tools/search/hard_jt.py check ovlNNNN <fn> <file.c>` compares the two (code and table); use it instead of `match.py` for a function that
has a `jtbl_` in its assembly. `hard_jt.py draft` gives m2c the table, `hard_jt.py auto overlays` tries every such function.
Not verified: a table that C places in `.rodata` next to other constants is compared as a run of consecutive words, not as a section.

## Order of work

Start with the smallest overlays: they match fastest and show the structure shared by many of them (initialisation,
update, draw functions). Then the large ones. Progress is added up over all the overlays in [PROGRESS.md](PROGRESS.md).

## Signatures

The four handlers of every actor overlay (init, destroy, update, draw) are typed `Actor *thisx, PlayState *play` by
`tools/signatures/sig_actors.py` and `tools/signatures/retype.py`; a handler whose bytes show that it takes only the first argument is typed
`Actor *thisx`, and one that reads actor fields we cannot name yet keeps its local types until the `Actor` structure is known.
Overlay functions come from the automatic drafts (`arg0`, `u8 *`, raw field offsets); their real types come from three sources, all
written to `config/overlays/protos.txt` by `tools/signatures/sig_ref.py` (same format as `signatures.txt`):
- the reference: a function with the evidence "bytes identical" in `names.txt`, or imported by `ref_import.py`, takes the prototype of its
  reference definition (callbacks such as `OverrideLimbDraw`, the helpers of an actor, the functions of the game states and menus); a function named only by rank and size
  takes it too when its assembly agrees (as many parameters, a float where it reads one, a pointer where it uses the register as a base);
- the calls of the overlay: a function that receives, untouched and at every call, a parameter of a typed function takes its type: the helper
  of an actor that every handler calls with `thisx` takes `EnTest *this` (the structure named after the `EnTest_Init` of `names.txt`), a
  parameter passed on from `play` is a `PlayState *`; the calls follow the straight line of the code, a
  parameter kept in the stack above the argument area and loaded back, and the calls through a word of the actor
  (`this->actionFunc(this, play)`): the functions stored in that word, directly or through the second parameter of a `SetupAction`, are
  called with the same arguments; a parameter passed untouched to a `boot` or `code` function whose
  prototype types it (`Actor *`, `PlayState *`, `Vec3f *`, `Vec3s *`) takes that type when every such call agrees;
- the assembly, as before (`arg0`, `void *`), for everything else.

The headers `include/generated/overlays/NNNN.h` print these prototypes. They declare the actor structures without fields
(`typedef struct EnTest EnTest;`) and include `actor.h` when a prototype uses it; types the header cannot say (the structures of the
reference, enums, `Gfx**`) are `void *` for a pointer and keep the function out of the table otherwise. The sources that are verified C are
retyped by `retype.py config/overlays/protos.txt` and kept only if they still compile to the bytes of the ROM, then `sig_header.py overlays
--apply` makes them use the header; a table line that a file refuses is dropped by `sig_ref.py prune`. The rule is in
[CONTRIBUTING.md](CONTRIBUTING.md#code-style), the count is the "Typed signatures" column of [PROGRESS.md](PROGRESS.md), and the plan is in
[ROADMAP.md](ROADMAP.md).

## Names

Overlay and function names come only from evidence, as for the other segments, and are written by
`python3 tools/search/ref_import.py run names` from the reference:
- `config/overlays/actors.txt` (`<file index> <name>`): the name of an overlay is the folder of the reference whose functions have the bytes of its own;
- `config/overlays/names.txt` (`<file index> <our name> <name>  # <evidence>`): a function whose bytes are those of exactly one function of the reference, or that sits
  at the same rank and with the same size between two such functions of one file.

The names are shown in `docs/OVERLAYS_INDEX.md` and as a comment next to the prototype in `include/generated/overlays/<index>.h`. They are not applied
to the folders and to the sources yet: those keep the file index and the address names.
