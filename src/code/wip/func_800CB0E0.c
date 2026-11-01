#include "types.h"

f32 func_800CAFC0(f32 value);

f32 Camera_ScaledStepToCeilF(f32 cur, f32 target, f32 stepScale, f32 minDiff) {
    f32 diff = cur - target;
    f32 pad;
    f32 ret;

    if (minDiff <= func_800CAFC0(diff)) {
        ret = target + (diff * stepScale);
    } else {
        ret = cur;
    }
    return ret;
}
