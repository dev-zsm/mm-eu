#include "types.h"

extern void AudioThread_QueueCmdS32(u32 op, s32 arg);

void Audio_PlayMainBgm(u8 seqId) {
    AudioThread_QueueCmdS32(0x82000000 | (seqId << 8), 1);
}
