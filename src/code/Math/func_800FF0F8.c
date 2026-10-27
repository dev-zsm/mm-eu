// FLAGS: -O2 -g3 -mips2
#include "types.h"
s32 Math_AsymStepToF(f32 *pValue, f32 target, f32 incrStep, f32 decrStep) {
    f32 step;
    if (*pValue <= target) {
        step = incrStep;
    } else {
        step = decrStep;
    }
    if (step != 0.0f) {
        if (target < *pValue) {
            step = -step;
        }
        *pValue += step;
        if (((*pValue - target) * step) >= 0.0f) {
            *pValue = target;
            return 1;
        }
    } else if (target == *pValue) {
        return 1;
    }
    return 0;
}
