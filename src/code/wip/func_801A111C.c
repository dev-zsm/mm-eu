// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u8 D_801CEFC8[];
extern u8 D_801CEFD0;

void AudioThread_QueueCmdS8(u32 a0, s8 a1);
void Audio_SetGanonsTowerBgmVolume(u8 a0);

void Audio_SetGanonsTowerBgmVolumeLevel(u8 level) {
    s32 i;
    s8 vol = 0;

    if (level == 0) {
        vol = 0x7F;
    }
    i = 0;
    do {
        AudioThread_QueueCmdS8(((i & 0xFF) << 8) | 0x07000000, vol);
        i = (i + 1) & 0xFF;
    } while (i < 16);
    if (level == 7) {
        D_801CEFD0 = 2;
    } else {
        Audio_SetGanonsTowerBgmVolume(D_801CEFC8[level & 7]);
    }
}
