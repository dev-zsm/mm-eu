#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    u8 pad0[0x2B0];
    Gfx* polyOpa;
} GfxCtx;

extern u8 D_801C2630[];

void Gfx_SetupDL56_Opa(GfxCtx* ctx) {
    Gfx* dl = ctx->polyOpa++;

    // one line: the ROM's scheduling depends on the command being emitted from a single source line
    dl->w0 = 0xDE000000; dl->w1 = (u32)D_801C2630;
}
