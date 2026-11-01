#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

extern u8 D_801C1F70[];

Gfx *Gfx_SetupDL20_NoCD(Gfx *gfx) {
    Gfx *g;

    g = gfx++;
    g->w0 = 0xDE000000;
    g->w1 = (u32)D_801C1F70;
    g = gfx++;
    g->w1 = 0xC0;
    g->w0 = 0xE3001801;
    g = gfx;
    return g;
}
