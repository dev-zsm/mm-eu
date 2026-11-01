// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"
extern f32 D_801D4E50;
f32 func_800CAFC0(f32 a);
f32 Camera_QuadraticAttenuation(f32 a, f32 b) {
    f32 v = func_800CAFC0(b);
    f32 t;
    f32 k;
    f32 ret;
    if (a < v) {
        ret = 1.0f;
    } else {
        k = 1.0f - D_801D4E50;
        t = a * k;
        if (v < t) {
            ret = (b * b * k) / (t * t);
        } else {
            t = a * D_801D4E50;
            ret = 1.0f - ((a - v) * (a - v) * D_801D4E50) / (t * t);
        }
    }
    return ret;
}
