// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct { u8 pad0[0xE]; u16 unkE; s16 unk10; s16 unk12; u8 pad14[8]; } AB;
typedef struct { AB items[5]; } AG;
typedef struct { u8 pad0[3]; u8 unk3; u8 pad4[0x3C]; AG grp[4]; } AT;
extern s32 AudioSynth_LoadReverbSamplesImpl(s32 a, u16 b, u16 c, s16 d, void *e);

s32 AudioSynth_LoadDefaultReverbSamples(s32 arg0, s32 arg1, AT *arg2, s16 arg3) {
    AB *p;
    s32 r;

    p = &arg2->grp[arg2->unk3].items[arg3];
    r = AudioSynth_LoadReverbSamplesImpl(arg0, 0xC70, p->unkE, p->unk10, arg2);
    if (p->unk12 != 0) {
        r = AudioSynth_LoadReverbSamplesImpl(r, (p->unk10 + 0xC70) & 0xFFFF, 0, p->unk12, arg2);
    }
    return r;
}
