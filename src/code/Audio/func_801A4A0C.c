// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern void AudioThread_QueueCmdS32(u32 a0, s32 a1);

void Audio_MuteSeqPlayerBgmSub(u8 flag) {
    if (flag == 1) {
        AudioThread_QueueCmdS32(0xF1030000, 0);
    } else {
        AudioThread_QueueCmdS32(0xF2030000, 0);
    }
}
