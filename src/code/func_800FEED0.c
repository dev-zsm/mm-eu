// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 Math_StepUntilAngleS(s16 *arg0, s16 arg1, s16 arg2) {
    s16 temp_v0;

    temp_v0 = *arg0;
    *arg0 = temp_v0 + arg2;
    if (((s16) (*arg0 - arg1) * (s16) (temp_v0 - arg1)) <= 0) {
        *arg0 = arg1;
        return 1;
    }
    return 0;
}
