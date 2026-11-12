// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u16 D_801D3DD0;

void AudioSeq_SetVolumeScale(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

void AudioSfx_RestoreBgmVolume(u8 arg0) {
    D_801D3DD0 &= (1 << arg0) ^ 0xFFFF;
    if (D_801D3DD0 == 0) {
        AudioSeq_SetVolumeScale(0, 2, 0x7F, 0xF);
        AudioSeq_SetVolumeScale(3, 2, 0x7F, 0xF);
    }
}
