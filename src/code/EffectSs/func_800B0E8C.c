#include "types.h"

s16 EffectSs_LerpInv(s16 a, s16 b, s32 divisor) {
    s16 result;

    if (divisor == 0) {
        result = b;
    } else {
        result = a + (s32)((f32)(b - a) / (f32)divisor);
    }
    return result;
}
