#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

extern u8 D_801C2300[];

void Gfx_SetupDL39_Ptr(Gfx **arg0) {
    Gfx *gfx = *arg0;
    Gfx *dl = gfx++;

    dl->w0 = 0xDE000000;
    dl->w1 = (u32)D_801C2300;
    *arg0 = gfx;
}
