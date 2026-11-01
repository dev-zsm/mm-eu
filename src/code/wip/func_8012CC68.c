#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

extern u8 D_801C28A0[];

// WIP: 6 instr differ; the ROM keeps the command pointer in v0 (copy of gfx before each gfx += 8).
Gfx *Gfx_SetupDL69_NoCD(Gfx *gfx) {
    { Gfx *_g = gfx++; _g->w0 = 0xDE000000; _g->w1 = (u32)D_801C28A0; }
    { Gfx *_g = gfx++; _g->w0 = 0xE3001801; _g->w1 = 0xC0; }
    return gfx;
}
