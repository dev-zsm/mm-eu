// FLAGS: -O2 -g0 -mips2
#include "types.h"

void AudioSeq_SetVolumeScale(s32, s32, u8, u8);

void Audio_SetMainBgmVolume(u8 targetVolume, u8 volumeFadeTimer) {
    AudioSeq_SetVolumeScale(0, 0, targetVolume, volumeFadeTimer);
}
