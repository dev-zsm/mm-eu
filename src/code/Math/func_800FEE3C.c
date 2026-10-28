#include "types.h"

s32 Math_StepToF(f32 *pValue, f32 target, f32 step) {
    if (step != 0.0f) {
        if (target < (*pValue)) {
            step = -step;
        }
        if (0) { }
        *pValue += step;
        if ((((*pValue) - target) * step) >= 0) {
            *pValue = target;
            return 1;
        }
    } else
        if (target == (*pValue)) {
        return 1;
    }
    return 0;
}
