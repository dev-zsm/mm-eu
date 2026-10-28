#include "types.h"
extern f32 D_801D5DBC;
typedef struct { s16 a; s16 x; s16 y; s16 z; } K;
void func_80124AC8(K *k, f32 t, f32 *out) {
    s32 ti = t;
    s16 hi;
    f32 f0;
    f32 f14;
    f32 f2;
    f32 sc;
    do {
        hi = k[1].a;
        k++;
    } while (hi < ti);
    f0 = k[-1].a;
    f2 = (t - f0) / (hi - f0);
    f14 = k[-1].x;
    sc = D_801D5DBC;
    out[0] = ((k[0].x - f14) * f2 + f14) * sc;
    f14 = k[-1].y;
    out[1] = ((k[0].y - f14) * f2 + f14) * sc;
    f14 = k[-1].z;
    out[2] = ((k[0].z - f14) * f2 + f14) * sc;
}
