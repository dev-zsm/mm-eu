#include "types.h"
typedef struct {
    f32 f0, f4, f8, fC, f10, f14, f18, f1C, f20;
    s32 i24, i28;
    f32 f2C, f30, f34;
    s32 i38, i3C;
    s16 h[13];
    s16 h5A;
    s16 h5C;
    u8 b5E, b5F;
} Eff;
void EffectSs_Reset(Eff *e) {
    s32 i;
    e->b5F = 0x27;
    e->f20 = 0.0f;
    e->f1C = 0.0f;
    e->f18 = 0.0f;
    e->f14 = 0.0f;
    e->f10 = 0.0f;
    e->fC = 0.0f;
    e->f34 = 0.0f;
    e->f30 = 0.0f;
    e->f2C = 0.0f;
    e->f8 = 0.0f;
    e->f4 = 0.0f;
    e->f0 = 0.0f;
    e->h5C = -1;
    e->h5A = 0;
    e->b5E = 0x80;
    e->i28 = 0;
    e->i24 = 0;
    e->i38 = 0;
    e->i3C = 0;
    e->h[0] = 0;
    for (i = 1; i < 13; i++) {
        e->h[i] = 0;
    }
}
