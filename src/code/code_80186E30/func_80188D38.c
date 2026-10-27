// FLAGS: -O2 -g0 -mips2
#include "types.h"
typedef struct { u8 pad0[3]; u8 n; u8 pad4[0x88]; } A;
typedef struct { u8 pad0[0xE]; u16 unkE; s16 unk10; s16 unk12; u8 pad14[8]; } B;
s32 AudioSynth_LoadReverbSamplesImpl(s32, u16, u16, s16, A *);

s32 func_80188D38(s32 a0, A *a, s16 idx) {
    B *b = (B *)((u8 *)a + a->n * 0x8C + 0x40) + idx;

    a0 = AudioSynth_LoadReverbSamplesImpl(a0, 0x3D0, b->unkE, b->unk10, a);
    if (b->unk12 != 0) {
        a0 = AudioSynth_LoadReverbSamplesImpl(a0, b->unk10 + 0x3D0, 0, b->unk12, a);
    }
    return a0;
}
