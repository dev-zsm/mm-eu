#include "types.h"

s32 Math_StepToIImpl(s32 start, s32 target, s32 step) {
    s32 v;

    if (start <= target) {
        v = start + step;
        if (v <= target) {
            return v;
        }
    } else {
        v = start - step;
        if (target <= v) {
            return v;
        }
    }
    return target;
}
