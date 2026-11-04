#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    u8 pad0[0x2B0];
    Gfx* p;
} GfxCtx;

extern void func_8012C530(GfxCtx* gfxCtx);
extern u8 D_E0002C8[];

void Environment_DrawLightningFlash(GfxCtx** pGfxCtx, u8 r, u8 g, u8 b, u8 a) {
    GfxCtx* gfxCtx = *pGfxCtx;
    Gfx* dl;

    func_8012C530(gfxCtx);

    dl = gfxCtx->p++;
    dl->w0 = 0xFA000000;
    dl->w1 = (r << 24) | (g << 16) | (b << 8) | a;

    dl = gfxCtx->p++;
    dl->w0 = 0xDE000000;
    dl->w1 = (u32)D_E0002C8;
}
