#include "types.h"

extern f32 D_801CDCE4[];
f32 func_8019BE08(s8 x) {
    f32 new_var2;
    long new_var;
    s8 idx;
    f32 *p;
    int new_var3;
    if (x > 0x40) {
        idx = 0x7F;
    } else
        if (x < (-0x40)) {
        idx = -0x80;
    } else {
        new_var3 = x * 127;
        new_var = x << 7;
        if (x >= 0) {
            idx = new_var3 / 64;
        } else {
            idx = new_var / 64;
        }
    }
    p = &D_801CDCE4[idx];
    new_var2 = *p;
    return new_var2;
    do { } while (0);
}
