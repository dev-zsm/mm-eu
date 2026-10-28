// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern f32 *D_801F3644;
f32 func_800884F0();
f32 func_800920E0(f32);

void Matrix_RotateXFNew(f32 x) {
    f32 *m;
    f32 p; // pad: match-only stack slot
    f32 c;
    f32 s;

    m = D_801F3644;
    m[0] = 1.0f;
    m[1] = 0.0f;
    m[2] = 0.0f;
    m[3] = 0.0f;
    m[4] = 0.0f;
    m[7] = 0.0f;
    m[8] = 0.0f;
    m[11] = 0.0f;
    m[12] = 0.0f;
    m[13] = 0.0f;
    m[14] = 0.0f;
    m[15] = 1.0f;
    if (x != 0.0f) {
        s = func_800884F0();
        c = func_800920E0(x);
        m[5] = c;
        m[10] = c;
        m[9] = -s;
        m[6] = s;
    } else {
        m[5] = 1.0f;
        m[6] = 0.0f;
        m[9] = 0.0f;
        m[10] = 1.0f;
    }
}
