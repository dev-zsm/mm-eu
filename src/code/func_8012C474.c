#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

extern u8 D_801C2660[];

Gfx *Gfx_SetupDL57(Gfx *gfx) {
    // one line: the ROM's scheduling depends on the body being emitted from a single source line (the empty if (0) is needed too)
    Gfx *g = gfx++; g->w0 = 0xDE000000; g->w1 = (u32)D_801C2660; if (0) { } return gfx;
}
