#include "types.h"

extern s32 BgCheck_SphVsFirstPolyImpl(void *colCtx, s32 a1, void *pos, void *a3, void *a4, f32 radius, s32 a5, s32 a6);

s32 BgCheck_SphVsFirstPoly(void *colCtx, void *pos, f32 radius) {
    u8 outPoly[4];
    u8 outDyna[4];

    return BgCheck_SphVsFirstPolyImpl(colCtx, 0, &outPoly, &outDyna, pos, radius, 0, 0);
}
