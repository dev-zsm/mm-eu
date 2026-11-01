#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    u8 pad0[0x2B0];
    Gfx *polyOpa;
    u8 pad2B4[0xC];
    Gfx *polyXlu;
} GfxCtx;

typedef struct {
    GfxCtx *gfxCtx;
} Play;

extern s32 D_801ED324;
Gfx *AnimatedMat_TwoLayerTexScroll(Play *play, void *params);

void AnimatedMat_DrawTwoTexScroll(Play *play, s32 segment, void *params) {
    Gfx *gfx = AnimatedMat_TwoLayerTexScroll(play, params);
    GfxCtx *g = play->gfxCtx;
    Gfx *d;

    if (D_801ED324 & 1) {
        d = g->polyOpa++;
        d->w0 = 0xDB060000 | ((segment * 4) & 0xFFFF);
        d->w1 = (u32)gfx;
    }
    if (D_801ED324 & 2) {
        d = g->polyXlu++;
        d->w0 = 0xDB060000 | ((segment * 4) & 0xFFFF);
        d->w1 = (u32)gfx;
    }
}
