// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[4];
    u8 unk4;
} Item;

extern s32 AudioSynth_LoadSubReverbSamples(void);

s32 AudioSynth_LoadSubReverbSamplesWithoutDownsample(s32 arg0, s32 arg1, Item *arg2, s16 arg3) {
    if (arg2->unk4 == 1) {
        arg0 = AudioSynth_LoadSubReverbSamples();
    }
    return arg0;
}
