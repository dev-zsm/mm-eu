// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern f32 D_80098170;
f32 func_800884F0(f32);
f32 func_800920E0(f32);

void func_80090050(f32 *m, f32 x, f32 y, f32 z, f32 s, f32 tx, f32 ty, f32 tz) {
    f32 sx;
    f32 cx;
    f32 sy;
    f32 cy;
    f32 sz;
    f32 cz;

    x = x * D_80098170;
    y = y * D_80098170;
    z = z * D_80098170;
    sx = func_800884F0(x);
    cx = func_800920E0(x);
    sy = func_800884F0(y);
    cy = func_800920E0(y);
    sz = func_800884F0(z);
    cz = func_800920E0(z);

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
