// FLAGS: -O2 -g3 -mips2
#include "types.h"
f32 Math_SinS(s16);
f32 Math_CosS(s16);
void SkinMatrix_SetXRotation(f32 *mf, s16 a) {
    f32 s;
    f32 c;
    if (a != 0) {
        s = Math_SinS(a);
        c = Math_CosS(a);
    } else {
        s = 0.0f;
        c = 1.0f;
    }
    mf[1] = 0.0f;
    mf[2] = 0.0f;
    mf[3] = 0.0f;
    mf[4] = 0.0f;
    mf[7] = 0.0f;
    mf[8] = 0.0f;
    mf[11] = 0.0f;
    mf[12] = 0.0f;
    mf[13] = 0.0f;
    mf[14] = 0.0f;
    mf[0] = 1.0f;
    mf[15] = 1.0f;
    mf[5] = c;
    mf[10] = c;
    mf[6] = s;
    mf[9] = -s;
}
