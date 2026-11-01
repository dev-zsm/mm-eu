// FLAGS: -O2 -g3 -mips2
#include "types.h"

void func_801253C8(s16 *a0, f32 *a1, s16 a2, f32 a3, f32 a4) {
    f32 t;
    f32 lim;

    if (*a0 < a2) {
        *a1 += a3;
    } else {
        *a1 -= a3;
    }
    t = *a1;
    if (t < -a4) {
        *a1 = -a4;
    } else {
        if (a4 < t) {
            lim = a4;
        } else {
            lim = t;
        }
        *a1 = lim;
    }
    *a0 += (s32)*a1;
    if ((s16)(s32)*a1 * (a2 - *a0) < 0) {
        *a0 = a2;
    }
}
