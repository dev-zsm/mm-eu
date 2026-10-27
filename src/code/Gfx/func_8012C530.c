#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    u8 pad0[0x2B0];
    Gfx* polyOpa;
} GfxCtx;

extern u8 D_801C2660[];

void func_8012C530(GfxCtx* ctx) {
    Gfx* dst = ctx->polyOpa++;

    // one line: the ROM's scheduling depends on the command being emitted from a single source line
    dst->w0 = 0xDE000000; dst->w1 = (u32)D_801C2660;
}
