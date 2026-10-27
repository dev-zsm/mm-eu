#include "types.h"

s32 Math_StepToAngleS(s16 *pValue, s16 target, s16 step) {
    s32 diff = target - *pValue;

    if (diff < 0) {
        step = -step;
    }
    if (diff >= 0x8000) {
        step = -step;
        diff = 0xFFFF0001 - -diff;
    } else if (diff < -0x7FFF) {
        diff += 0xFFFF;
        step = -step;
    }
    if (step != 0) {
        *pValue += step;
        if (step * diff <= 0) {
            *pValue = target;
            return 1;
        }
    } else if (target == *pValue) {
        return 1;
    }
    return 0;
}
