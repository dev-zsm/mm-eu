#include "types.h"

void Keyframe_MorphInterpolateLinear(s16 *dst, s16 *target, f32 t) {
    s32 i;
    f32 from;
    f32 to;

    for (i = 0; i < 3; i++) {
        if (*dst != *target) {
            from = *dst;
            to = *target;
            *dst = from + (to - from) * t;
        }
        dst++;
        target++;
    }
}
