// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

f32 Keyframe_Interpolate(f32 t, f32 delta, f32 x0, f32 x1, f32 v0, f32 v1) {
    f32 temp_f16;
    f32 temp_f18;
    f32 temp_f2;

    temp_f2 = t * t;
    temp_f16 = temp_f2 * t;
    temp_f18 = (temp_f2 * 3.0f) - (2.0f * temp_f16);
    return ((1.0f - temp_f18) * x0) + (temp_f18 * x1) + (((((temp_f16 - (2.0f * temp_f2)) + t) * v0) + ((temp_f16 - temp_f2) * v1)) * delta);
}
