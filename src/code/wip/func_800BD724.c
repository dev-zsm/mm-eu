#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    u8 pad0[0x2B4];
    Gfx *polyOpaEnd;
} GraphicsContext;

Gfx *func_800BD724(GraphicsContext *gfxCtx) {
    Gfx *gfx = gfxCtx->polyOpaEnd - 2;

    gfxCtx->polyOpaEnd = gfx;
    gfx[0].w0 = 0xE200001C;
    gfx[0].w1 = 0xC81049F8;
    gfx[1].w0 = 0xDF000000;
    gfx[1].w1 = 0;
    return gfx;
}
