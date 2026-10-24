// FLAGS: -O2 -g0 -mips2
#include "types.h"

void AudioSeq_SetVolumeScale(s32, s32, u8, u8);

void Audio_SetMainBgmVolume(u8 arg0, u8 arg1) {
    AudioSeq_SetVolumeScale(0, 0, arg0, arg1);
}
