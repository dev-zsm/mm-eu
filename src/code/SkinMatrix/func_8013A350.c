#include "types.h"

extern f32 Math_SinS(s16 a);
extern f32 Math_CosS(s16 a);

void SkinMatrix_SetYRotation(f32 *mf, s16 a) {
    f32 sinA;
    f32 cosA;

    if (a != 0) {
        sinA = Math_SinS(a);
        cosA = Math_CosS(a);
    } else {
        sinA = 0.0f;
        cosA = 1.0f;
    }
    mf[1] = 0.0f;
    mf[3] = 0.0f;
    mf[4] = 0.0f;
    mf[6] = 0.0f;
    mf[7] = 0.0f;
    mf[9] = 0.0f;
    mf[11] = 0.0f;
    mf[12] = 0.0f;
    mf[13] = 0.0f;
    mf[14] = 0.0f;
    mf[5] = 1.0f;
    mf[15] = 1.0f;
    mf[0] = cosA;
    mf[10] = cosA;
    mf[2] = -sinA;
    mf[8] = sinA;
}
