// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[4];
    u32 phase;
    s16 *table;
    u8 padC[4];
    f32 rate;
} Vibrato;

s16 AudioEffects_GetVibratoPitchChange(Vibrato *v) {
    u32 idx;

    v->phase += (s32)v->rate;
    idx = (v->phase >> 10) & 0x3F;
    return v->table[idx];
}
