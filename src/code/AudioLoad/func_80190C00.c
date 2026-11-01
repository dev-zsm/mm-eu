// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "code_funcs.h"


void AudioLoad_GetSampleBank(s32 arg0, s32 arg1) {
    AudioLoad_TrySyncLoadSampleBank(arg0, arg1, 1);
}
