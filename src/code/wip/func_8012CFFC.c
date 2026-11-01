#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    u8 pad0[0x2B4];
    Gfx* dl;
} GfxCtx;

Gfx* Gfx_TexScroll(GfxCtx* gfxCtx, u32 x, u32 y, s32 width, s32 height) {
    Gfx* dl = gfxCtx->dl - 4;

    gfxCtx->dl = dl;
    x &= 0x7FF;
    y &= 0x7FF;

    dl[0].w0 = 0xE8000000;
    dl[0].w1 = 0;
    dl[1].w0 = 0xF2000000 | ((x & 0xFFF) << 12) | (y & 0xFFF);
    dl[1].w1 = ((((width - 1) * 4 + x) & 0xFFF) << 12) | ((y + (height - 1) * 4) & 0xFFF);
    dl[2].w0 = 0xDF000000;
    dl[2].w1 = 0;
    return dl;
}
