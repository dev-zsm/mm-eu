#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    u8 pad0[0x2B4];
    Gfx *dlTail;
} GraphicsContext;

Gfx *Gfx_PrimColor(GraphicsContext *gfxCtx, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    Gfx *dl;

    gfxCtx->dlTail -= 2;
    dl = gfxCtx->dlTail;
    dl[0].w0 = 0xFA000000 | (arg1 & 0xFF);
    dl[0].w1 = (arg2 << 24) | ((arg3 & 0xFF) << 16) | ((arg4 & 0xFF) << 8) | (arg5 & 0xFF);
    dl[1].w0 = 0xDF000000;
    dl[1].w1 = 0;
    return dl;
}
