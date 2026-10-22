// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern f32 D_80098170;
f32 __sinf(f32);
f32 __cosf(f32);

void guPositionF(f32 *m, f32 x, f32 y, f32 z, f32 s, f32 tx, f32 ty, f32 tz) {
    f32 sx;
    f32 cx;
    f32 sy;
    f32 cy;
    f32 sz;
    f32 cz;

    x = x * D_80098170;
    y = y * D_80098170;
    z = z * D_80098170;
    sx = __sinf(x);
    cx = __cosf(x);
    sy = __sinf(y);
    cy = __cosf(y);
    sz = __sinf(z);
    cz = __cosf(z);

    m[0] = cy * cz * s;
    m[1] = cy * sz * s;
    m[2] = -sy * s;
    m[3] = 0.0f;
    m[4] = (sx * sy * cz - cx * sz) * s;
    m[5] = (sx * sy * sz + cx * cz) * s;
    m[6] = sx * cy * s;
    m[7] = 0.0f;
    m[8] = (cx * sy * cz + sx * sz) * s;
    m[9] = (cx * sy * sz - sx * cz) * s;
    m[10] = cx * cy * s;
    m[11] = 0.0f;
    m[12] = tx;
    m[13] = ty;
    m[14] = tz;
    m[15] = 1.0f;
}
