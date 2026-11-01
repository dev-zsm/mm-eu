// STATUS: 14 instructions differ: ROM keeps the new display list pointer in v1 and builds the color in another order
#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    u8 pad0[0x2B4];
    Gfx *dlHead;
} GraphicsContext;

Gfx *Gfx_EnvColor(GraphicsContext *gfxCtx, s32 r, s32 g, s32 b, s32 a) {
    Gfx *dl = gfxCtx->dlHead;

    gfxCtx->dlHead = dl - 2;
    dl -= 2;
    dl[0].w0 = 0xFB000000;
    dl[0].w1 = (r << 24) | ((g & 0xFF) << 16) | ((b & 0xFF) << 8) | (a & 0xFF);
    dl[1].w0 = 0xDF000000;
    dl[1].w1 = 0;
    return dl;
}
