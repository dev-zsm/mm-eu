#include "types.h"

s32 Math_StepToC(s8 *pValue, s8 target, s8 step) {
    if (step != 0) {
        if (target < *pValue) {
            step = -step;
        }
        *pValue += step;
        if ((*pValue - target) * step >= 0) {
            *pValue = target;
            return 1;
        }
    } else if (target == *pValue) {
        return 1;
    }
    return 0;
}
