// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[3];
    u8 unk3;
} A;

typedef struct {
    u8 pad0[0xE];
    u16 unkE;
    s16 unk10;
    s16 unk12;
} B;

extern s32 AudioSynth_SaveReverbSamplesImpl(s32 a0, u16 a1, u16 a2, s16 a3, void *a4);

s32 func_80188DE0(s32 a0, A *arg1, s16 arg2) {
    B *p = (B *)((u8 *)arg1 + arg1->unk3 * 0x8C + arg2 * 0x1C + 0x40);
    s32 r = AudioSynth_SaveReverbSamplesImpl(a0, 0x3D0, p->unkE, p->unk10, arg1);

    if (p->unk12 != 0) {
        r = AudioSynth_SaveReverbSamplesImpl(r, p->unk10 + 0x3D0, 0, p->unk12, arg1);
    }
    return r;
}

// ROM has an empty stub function (jr ra) right after this one.
void func_80188DE0_stub(void) {}
