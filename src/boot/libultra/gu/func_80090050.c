// FLAGS: -O2 -g0 -mips2 -Wab,-r4300_mul
// dtor is a function-static in the original source, so the object carries its own .data (the segment build keeps this function as assembly)
#include "gu.h"
#include "libm.h"

void guPositionF(MtxF mf, f32 roll, f32 pitch, f32 yaw, f32 scale, f32 x, f32 y, f32 z) {
    static f32 dtor = 3.1415926 / 180.0;
    f32 sinRoll;
    f32 sinPitch;
    f32 sinYaw;
    f32 cosRoll;
    f32 cosPitch;
    f32 cosYaw;

    roll = roll * dtor;
    pitch = pitch * dtor;
    yaw = yaw * dtor;
    sinRoll = __sinf(roll);
    cosRoll = __cosf(roll);
    sinPitch = __sinf(pitch);
    cosPitch = __cosf(pitch);
    sinYaw = __sinf(yaw);
    cosYaw = __cosf(yaw);

    mf[0][0] = cosPitch * cosYaw * scale;
    mf[0][1] = cosPitch * sinYaw * scale;
    mf[0][2] = -sinPitch * scale;
    mf[0][3] = 0.0f;
    mf[1][0] = (sinRoll * sinPitch * cosYaw - cosRoll * sinYaw) * scale;
    mf[1][1] = (sinRoll * sinPitch * sinYaw + cosRoll * cosYaw) * scale;
    mf[1][2] = sinRoll * cosPitch * scale;
    mf[1][3] = 0.0f;
    mf[2][0] = (cosRoll * sinPitch * cosYaw + sinRoll * sinYaw) * scale;
    mf[2][1] = (cosRoll * sinPitch * sinYaw - sinRoll * cosYaw) * scale;
    mf[2][2] = cosRoll * cosPitch * scale;
    mf[2][3] = 0.0f;
    mf[3][0] = x;
    mf[3][1] = y;
    mf[3][2] = z;
    mf[3][3] = 1.0f;
}
