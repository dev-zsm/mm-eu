#include "types.h"

extern s32 BgCheck_CheckCeilingImpl(void *colCtx, s32 a1, void *pos, void *a3, f32 checkHeight, void *outPoly, void *outBgId, s32 a7);

s32 BgCheck_AnyCheckCeiling(void *colCtx, void *pos, void *a2, f32 checkHeight) {
    u8 outBgId[4];
    u8 outPoly[4];

    return BgCheck_CheckCeilingImpl(colCtx, 0, pos, a2, checkHeight, &outBgId, &outPoly, 0);
}
