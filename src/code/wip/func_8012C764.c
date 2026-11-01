#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

extern Gfx D_801C2900[];

Gfx *Gfx_SetupDL71(Gfx *gfx) {
    Gfx *dl = gfx;

    dl->w0 = 0xDE000000;
    dl->w1 = (u32)D_801C2900;
    gfx++;
    return gfx;
}
