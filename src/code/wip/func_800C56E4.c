#include "types.h"

typedef struct {
    u8 pad0[0x40];
    s32 unk40;
} Ctx;

extern s32 BgCheck_GetStaticLookup(s32, s32);
extern s32 BgCheck_SphVsFirstStaticPoly(s32, u16, Ctx *, s32, f32, s32, u16, s32);
extern s32 BgCheck_SphVsFirstDynaPoly(Ctx *, u16, s32, s32 *, s32, f32, s32, u16);

s32 BgCheck_SphVsFirstPolyImpl(Ctx *ctx, u16 a1, s32 a2, s32 *a3, s32 a4, f32 a5, s32 a6, u16 a7) {
    s32 r;

    *a3 = 0x32;
    r = BgCheck_GetStaticLookup(ctx->unk40, a4);
    if (r != 0) {
        if (BgCheck_SphVsFirstStaticPoly(r, a1, ctx, a4, a5, a2, a7, a6) != 0 || BgCheck_SphVsFirstDynaPoly(ctx, a1, a2, a3, a4, a5, a6, a7) != 0) {
            return 1;
        }
    }
    return 0;
}
