#include "types.h"

typedef struct {
    s32 w[16];
} Fix;

void func_801792D0(Fix *d, f32 a1, f32 a2, f32 a3, f32 a4, f32 a5, f32 a6) {
    s32 t;
    s32 u;
    s16 *h = (s16 *)d;

    d->w[1] = 0;
    d->w[9] = 0;
    d->w[3] = 0;
    d->w[0xB] = 0;
    d->w[4] = 0;
    t = a1 * 65536.0f;
    u = a2 * 65536.0f;
    d->w[0] = t;
    h[1] = 0;
    d->w[8] = t << 16;
    d->w[2] = (u32)u >> 16;
    d->w[0xA] = u & 0xFFFF;
    d->w[0xC] = 0;
    t = a3 * 65536.0f;
    d->w[5] = t;
    h[0xB] = 0;
    d->w[0xD] = t << 16;
    t = a4 * 65536.0f;
    h[0xC] = (u32)t >> 16;
    h[0x1C] = t;
    t = a5 * 65536.0f;
    h[0xD] = (u32)t >> 16;
    h[0x1D] = t;
    h[0xF] = 1;
    t = a6 * 65536.0f;
    h[0xE] = (u32)t >> 16;
    d->w[0xF] = t << 16;
}
