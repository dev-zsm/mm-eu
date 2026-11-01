#include "types.h"

typedef struct { u32 w0, w1; } Gfx;
typedef struct { u8 pad0[0x2C0]; Gfx *p; } GfxCtx;
typedef struct { GfxCtx *gfx; } Play;

extern u8 D_801CA710[];
extern void func_8012CA10(GfxCtx *);
extern u32 DebugDisplay_PathDisplayList(GfxCtx *, s32);

void DebugDisplay_DrawPath(Play *play, s32 a1) {
    GfxCtx *gfx = play->gfx;
    Gfx *dl;

    func_8012CA10(gfx);
    dl = gfx->p;
    gfx->p = dl + 1;
    dl->w0 = 0xDA380003;
    dl->w1 = (u32)D_801CA710;
    dl = gfx->p;
    gfx->p = dl + 1;
    dl->w0 = 0xDE000000;
    dl->w1 = DebugDisplay_PathDisplayList(play->gfx, a1);
}
