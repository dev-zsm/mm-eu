// FLAGS: -O2 -g3 -mips2
#include "types.h"

f32 Math_SinS(s16 a);
f32 Math_CosS(s16 a);

void SkinMatrix_SetZRotation(f32 *m, s16 z) {
    f32 s;
    f32 c;

    if (z != 0) {
        s = Math_SinS(z);
        c = Math_CosS(z);
    } else {
        s = 0.0f;
        c = 1.0f;
    }
    m[2] = 0.0f;
    m[3] = 0.0f;
    m[6] = 0.0f;
    m[7] = 0.0f;
    m[8] = 0.0f;
    m[9] = 0.0f;
    m[11] = 0.0f;
    m[12] = 0.0f;
    m[13] = 0.0f;
    m[14] = 0.0f;
    m[10] = 1.0f;
    m[15] = 1.0f;
    m[0] = c;
    m[5] = c;
    m[1] = s;
    m[4] = -s;
}
