// FLAGS: -O2 -g0 -mips2
#include "types.h"

void AudioThread_QueueCmdS8(u32 opArgs, s8 data);

void Audio_SetSfxReverbIndexExceptOcarinaBank(u8 reverbIndex) {
    u8 channelIndex;

    for (channelIndex = 0; channelIndex < 16; channelIndex++) {
        if (channelIndex != 13) {
            // the (u32) cast is only there to match the register use
            AudioThread_QueueCmdS8(0x11020000 | (((u32)channelIndex & 0xFF) << 8), reverbIndex);
        }
    }
}
