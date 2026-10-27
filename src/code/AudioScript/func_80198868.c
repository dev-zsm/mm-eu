// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u32 unk0_31 : 1;
    u32 unk0_30 : 1;
} SeqPlayer8868;

typedef struct {
    u8 pad0[0x50];
    SeqPlayer8868 *unk50;
} SeqChannel8868;

typedef struct {
    u8 unk0_7 : 1;
    u8 unk0_6 : 1;
    u8 pad1[0x5F];
    SeqChannel8868 *unk60;
} SeqLayer8868;

extern SeqChannel8868 D_801FFCF0;

void AudioPlayback_SeqLayerNoteDecay(SeqLayer8868 *);
void AudioPlayback_SeqLayerNoteRelease(SeqLayer8868 *);

void AudioScript_SeqLayerDisable(SeqLayer8868 *layer) {
    if (layer != NULL) {
        if ((layer->unk60 != &D_801FFCF0) && (layer->unk60->unk50->unk0_30 == 1)) {
            AudioPlayback_SeqLayerNoteRelease(layer);
        } else {
            AudioPlayback_SeqLayerNoteDecay(layer);
        }
        layer->unk0_7 = 0;
        layer->unk0_6 = 1;
    }
}
