#include "types.h"

extern f32 D_801D721C;
extern f32 D_801D7220;

void func_80163B2C(f32 t, f32 *out) {
    f32 u = 1.0f - t;
    f32 t2 = t * t;
    f32 t3 = t2 * t;

    out[0] = u * u * u * D_801D721C;
    out[1] = t3 * 0.5f - t2 + D_801D7220;
    out[2] = t3 * -0.5f + t2 * 0.5f + t * 0.5f + D_801D721C;
    out[3] = t3 * D_801D721C;
}
