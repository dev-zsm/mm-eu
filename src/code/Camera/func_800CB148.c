#include "types.h"

s16 Camera_ScaledStepToCeilS(s16 cur, s16 target, f32 scale, s16 minDiff) {
    s16 diff = cur - target;
    s32 absDiff;
    s32 ret;

    if (diff >= 0) {
        absDiff = diff;
    } else {
        absDiff = -diff;
    }
    if (absDiff >= minDiff) {
        ret = target + (s16)(diff * scale + 0.5f);
    } else {
        ret = cur;
    }
    return ret;
}
