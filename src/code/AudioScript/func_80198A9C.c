// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x10];
} SequenceChannel;

typedef struct {
    u8 pad0[0x38];
    SequenceChannel *channels[16];
} SequencePlayer;

extern SequenceChannel D_801FFCF0;
void AudioScript_SequenceChannelDisable(SequenceChannel *channel);

void AudioScript_SequencePlayerDisableChannels(SequencePlayer *seqPlayer, u16 channelBits) {
    s32 i;
    SequenceChannel *channel;

    for (i = 0; i < 16; i++) {
        channel = seqPlayer->channels[i];
        if (((u32)channel != (u32)&D_801FFCF0) == 1) {
            AudioScript_SequenceChannelDisable(channel);
        }
    }
}
