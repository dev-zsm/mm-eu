// FLAGS: -O2 -g0 -mips2
#include "types.h"
typedef struct { u8 pad0[0xE]; u16 e; s16 n10; s16 n12; } Ent;
typedef struct { u8 pad0[3]; u8 idx; } Hdr;
s32 AudioSynth_LoadReverbSamplesImpl(s32 a, u16 b, u16 c, s16 d, void *e);
s32 AudioSynth_LoadSubReverbSamples(s32 a, s32 unused, Hdr *h, s16 i) {
    Ent *p = (Ent *)((u8 *)h + h->idx * 0x8C + i * 0x1C + 0x158);
    s32 r = AudioSynth_LoadReverbSamplesImpl(a, 0xC70, p->e, p->n10, h);
    if (p->n12 != 0) {
        r = AudioSynth_LoadReverbSamplesImpl(r, p->n10 + 0xC70, 0, p->n12, h);
    }
    return r;
}
