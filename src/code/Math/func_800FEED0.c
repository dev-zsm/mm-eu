// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

s32 Math_StepUntilAngleS(s16 *pValue, s16 target, s16 step) {
    s16 temp_v0;

    temp_v0 = *pValue;
    *pValue = temp_v0 + step;
    if (((s16) (*pValue - target) * (s16) (temp_v0 - target)) <= 0) {
        *pValue = target;
        return 1;
    }
    return 0;
}
