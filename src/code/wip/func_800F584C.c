#include "types.h"

f32 Environment_LerpWeight(u16 a, u16 b, u16 c) {
    f32 d;
    f32 r;
    u16 t;

    d = a - b;
    t = a;
    if (d != 0.0f) {
        r = 1.0f - (f32)(t - c) / d;
        if (r >= 1.0f) {
            return 1.0f;
        }
        return r;
    }
    return 1.0f;
}
