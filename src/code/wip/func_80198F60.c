// FLAGS: -O2 -g0
#include "types.h"
typedef struct Layer {
    u8 flags;
    u8 pad1[0x2F];
    u8 unk30;
    u8 pad31[0xB];
    struct Layer *unk3C;
    u8 pad40[4];
    struct Layer *unk44;
} Layer;
void AudioPlayback_SeqLayerNoteDecay(Layer *);
void AudioScript_SeqLayerProcessScriptStep1(Layer *l) {
    Layer *p;
    s32 v;
    if (!(*(u32 *)l & 0x10000000)) {
        AudioPlayback_SeqLayerNoteDecay(l);
    } else {
        p = l->unk3C;
        if (p != NULL && l == p->unk44) {
            AudioPlayback_SeqLayerNoteDecay(l);
        }
    }
    v = l->unk30 & ~0x80;
    if (v == 1 || v == 2) {
        l->unk30 = 0;
    }
    l->flags |= 1;
}
