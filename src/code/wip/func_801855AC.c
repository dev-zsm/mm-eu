#include "types.h"

typedef struct { u32 w0; u32 w1; } Gfx;
typedef struct {
    /* 0x000 */ u8 pad0[0x2B0];
    /* 0x2B0 */ Gfx *opa;
    /* 0x2B4 */ u8 pad2B4[0x2C0 - 0x2B4];
    /* 0x2C0 */ Gfx *xlu;
} GfxCtx;
typedef struct { GfxCtx *gfx; } State;

extern void Keyframe_DrawFlexLimb(State *state, s32 a1, s32 *p, s32 a3, s32 a4, s32 a5, s32 *pa2);

void Keyframe_DrawFlex(State *state, s32 a1, s32 dl, s32 a3, s32 a4, s32 a5) {
    s32 sp3C;
    s32 pad[2];

    if (dl != 0) {
        GfxCtx *gfx = state->gfx;
        Gfx *p;

        p = gfx->opa++;
        p->w0 = 0xDB060034;
        p->w1 = dl;
        p = gfx->xlu++;
        p->w0 = 0xDB060034;
        p->w1 = dl;
        sp3C = 0;
        Keyframe_DrawFlexLimb(state, a1, &sp3C, a3, a4, a5, &dl);
    }
}
