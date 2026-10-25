// FLAGS: -O2 -g0
#include "types.h"

typedef struct {
    /* 0x00 */ u8 unk0;
    /* 0x02 */ u16 cur;
    /* 0x04 */ u16 speed;
    /* 0x08 */ f32 extent;
} Portamento;

extern f32 D_801CD8E4[];

f32 AudioEffects_UpdatePortamento(Portamento *portamento) {
    u32 index;
    f32 out; // result local: makes the result land in $f2 then move to $f0, as in the ROM

    portamento->cur += portamento->speed;
    index = (portamento->cur >> 8) & 0xFF;
    if (index >= 0x7F) {
        index = 0x7F;
        portamento->unk0 = 0;
    }
    out = ((D_801CD8E4[index] - 1.0f) * portamento->extent) + 1.0f;
    return out;
}
