// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    /* 0x00 */ u8 enabled : 1;
    /* 0x00 */ u8 finished : 1;
    /* 0x00 */ u8 unk0_5 : 1;
    /* 0x00 */ u8 unk0_4 : 5;
    /* 0x01 */ u8 pad1[0x87];
    /* 0x88 */ u8 notePool[1];
} SequenceChannel;

extern void AudioScript_SeqLayerFree(SequenceChannel *channel, s32 layerIndex);
extern void AudioList_ClearNotePool(void *pool);

void AudioScript_SequenceChannelDisable(SequenceChannel *channel) {
    s32 i;

    channel->finished = 1;
    for (i = 0; i < 4; i++) {
        AudioScript_SeqLayerFree(channel, i);
    }
    AudioList_ClearNotePool(channel->notePool);
    channel->enabled = 0;
}
