#include "types.h"

typedef struct {
    u8 pad0[0xC8];
    s8 io[8];
} SeqChannel;

typedef struct {
    u32 enabled : 1;
    u32 pad : 31;
    u8 pad4[0x34];
    SeqChannel *channels[4];
    u8 pad48[0x160 - 0x48];
} SequencePlayer;

typedef struct {
    u8 pad0[0x4460];
    SequencePlayer seqPlayers[4];
} AudioContext;

extern AudioContext D_801F84B0;

s8 AudioThread_GetChannelIO(s32 seqIndex, s32 channelIndex, s32 ioPort) {
    SequencePlayer *player = &D_801F84B0.seqPlayers[seqIndex];
    SeqChannel *channel;

    if (player->enabled) {
        channel = player->channels[channelIndex];
        return channel->io[ioPort];
    }
    return -1;
}
