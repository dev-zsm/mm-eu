// FLAGS: -O2 -g0
#include "types.h"

extern f32 D_800976C4;
extern f32 D_80099384;
extern f32 D_80099388;

f32 Math_FAtanContFracF(f32 arg0) {
    s32 v;
    s32 i;
    f32 lo;
    f32 one;
    f32 t;
    f32 a;
    f32 s;
    f32 n;
    f32 d;
    f32 r;

    lo = -1.0f;
    one = 1.0f;
    if (lo <= arg0 && arg0 <= one) {
        v = 0;
    } else if (one < arg0) {
        v = 1;
        arg0 = one / arg0;
    } else if (arg0 < lo) {
        v = -1;
        arg0 = one / arg0;
    } else {
        return D_800976C4;
    }

    t = arg0 * arg0;
    s = 0.0f;
    a = 8.0f;
    i = 8;
    do {
        i -= 4;
        n = (a * a) * t;
        d = ((a + a) + one) + s;
        s = n / d;
        a = a - one;
        n = (a * a) * t;
        d = ((a + a) + one) + s;
        s = n / d;
        a = a - one;
        n = (a * a) * t;
        d = ((a + a) + one) + s;
        s = n / d;
        a = a - one;
        n = (a * a) * t;
        d = ((a + a) + one) + s;
        s = n / d;
        a = a - one;
    } while (i != 0);

    r = arg0 / (one + s);
    if (v != 0) {
        if (v > 0) {
            return D_80099384 - r;
        }
        return D_80099388 - r;
    }
    return r;
}
