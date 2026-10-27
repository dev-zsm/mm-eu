// FLAGS: -O2 -g0 -mips2
#include "types.h"

void AudioLoad_TrySyncLoadSampleBank(s32 a0, s32 a1, s32 a2);

void AudioLoad_GetSampleBank(s32 arg0, s32 arg1) {
    AudioLoad_TrySyncLoadSampleBank(arg0, arg1, 1);
}
