// FLAGS: -O2 -g3 -mips2
#include "types.h"

s16 Camera_ScaledStepToFloorS(s16 arg0, s16 arg1, f32 arg2, s16 arg3) {
    s16 temp;
    s32 absv;
    s32 result;
    temp = arg0 - arg1;
    if (temp >= 0) {
        absv = temp;
    } else {
        absv = -temp;
    }
    if (absv >= arg3) {
        result = arg1 + (s16)(s32)(((f32)temp * arg2) + 0.5f);
    } else {
        result = arg1;
    }
    return result;
}
