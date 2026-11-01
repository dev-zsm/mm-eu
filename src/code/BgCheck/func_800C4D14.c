#include "types.h"

extern void BgCheck_CheckCeilingImpl(s32 a0, s32 a1, s32 a2, s32 a3, f32 a4, s32 a5, s32 a6, s32 a7);

void BgCheck_EntityCheckCeiling(s32 a0, s32 a1, s32 a2, f32 a3, s32 a4, s32 a5, s32 a6) {
    BgCheck_CheckCeilingImpl(a0, 2, a1, a2, a3, a4, a5, a6);
}
