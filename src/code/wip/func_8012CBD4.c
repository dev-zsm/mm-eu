// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

extern u8 D_801C2810[];

Gfx *Gfx_SetupDL66(Gfx *dl) {
    Gfx *g = dl;

    g->w0 = 0xDE000000;
    g->w1 = (u32)D_801C2810;
    dl = g + 1;
    return dl;
}
