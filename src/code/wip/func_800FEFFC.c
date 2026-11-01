// FLAGS: -O2 -g0 -mips2
#include "types.h"

s32 Math_AsymStepToS(s16 *pValue, s16 target, s16 incrUp, s16 incrDown) {
    s16 step = incrDown;

    if (target - *pValue >= 0) {
        step = incrUp;
    }
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
