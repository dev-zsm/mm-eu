// FLAGS: -O2 -g3 -mips2
#include "types.h"

f32 Keyframe_Interpolate(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    f32 temp_f16;
    f32 temp_f18;
    f32 temp_f2;

    temp_f2 = arg0 * arg0;
    temp_f16 = temp_f2 * arg0;
    temp_f18 = (temp_f2 * 3.0f) - (2.0f * temp_f16);
    return ((1.0f - temp_f18) * arg2) + (temp_f18 * arg3) + (((((temp_f16 - (2.0f * temp_f2)) + arg0) * arg4) + ((temp_f16 - temp_f2) * arg5)) * arg1);
}
