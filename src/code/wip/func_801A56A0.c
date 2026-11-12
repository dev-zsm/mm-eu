// FLAGS: -O2 -g3 -mips2
#include "types.h"
void AudioSeq_QueueSeqCmd(s32);
u16 AudioSeq_GetActiveSeqId(u8);
s32 AudioSeq_IsSeqCmdNotQueued(u32, u32);

extern s8 D_801F4BE8;
extern u16 D_801F83FA;

void Audio_SetAmbienceChannelIO(u8 channelIndexRange, u8 ioPort, u8 ioData) {
    u8 firstChannelIndex;
    u8 lastChannelIndex;
    u8 channelIndex;

    if ((D_801F83FA == 1) || (AudioSeq_IsSeqCmdNotQueued(0xF00000FF, 1) == 0)) {
        if (((channelIndexRange << 8) + ioPort) == 0x101 && AudioSeq_GetActiveSeqId(3) != 0x2F) {
            D_801F4BE8 = 0;
        }
        firstChannelIndex = channelIndexRange >> 4;
        lastChannelIndex = channelIndexRange & 0xF;
        if (firstChannelIndex == 0) {
            firstChannelIndex = lastChannelIndex;
        }
        for (channelIndex = firstChannelIndex; channelIndex <= lastChannelIndex; channelIndex++) {
            AudioSeq_QueueSeqCmd((ioPort << 0x10) | 0x84000000 | (channelIndex << 8) | ioData);
        }
    }
}
