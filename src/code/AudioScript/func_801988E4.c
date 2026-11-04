// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x54];
    void *layers[4];
} SeqChannel;

extern u8 D_801FFDD8[];
extern void AudioList_PushBack(void *list, void *item);
extern void AudioScript_SeqLayerDisable(void *layer);

void AudioScript_SeqLayerFree(SeqChannel *channel, s32 layerIndex) {
    void *layer = channel->layers[layerIndex];

    if (layer != NULL) {
        AudioList_PushBack(D_801FFDD8, (u8 *)layer + 0x80);
        AudioScript_SeqLayerDisable(layer);
        channel->layers[layerIndex] = NULL;
    }
}
