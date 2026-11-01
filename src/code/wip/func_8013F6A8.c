#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    u8 pad0[0x2B0];
    Gfx *polyOpa;
    u8 pad2B4[0xC];
    Gfx *overlay;
} GfxCtx;

typedef struct {
    u8 pad0[4];
    GfxCtx *gfx;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
} View;

extern s32 func_80161DAC();
extern void View_SetScissor(Gfx **, s32, s32, s32, s32);

void View_ApplyLetterbox(View *view) {
    GfxCtx *gfx;
    s32 lb;
    s32 y;
    s32 ulx;
    s32 uly;
    s32 lrx;
    s32 lry;
    Gfx *dl;
    Gfx *g;

    y = 0;
    gfx = view->gfx;
    lb = func_80161DAC(view);
    if (lb < 0) {
        lb = 0;
    } else if (lb > 0x78) {
        lb = 0x78;
    }
    ulx = view->unk10 + y;
    uly = view->unk8 + lb;
    lrx = view->unk14 - y;
    lry = view->unkC - lb;

    g = gfx->polyOpa++;
    g->w1 = 0;
    g->w0 = 0xE7000000;
    dl = gfx->polyOpa;
    View_SetScissor(&dl, ulx, uly, lrx, lry);
    gfx->polyOpa = dl;

    g = gfx->overlay++;
    g->w1 = 0;
    g->w0 = 0xE7000000;
    dl = gfx->overlay;
    View_SetScissor(&dl, ulx, uly, lrx, lry);
    gfx->overlay = dl;
}
