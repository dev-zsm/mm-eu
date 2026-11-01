#include "types.h"
typedef struct { u8 limbCount; u8 pad1[0x1F]; s32 u20; s32 u24; f32 weight; f32 rate; } Skel;
extern f32 D_801C9E1C;
void SkelAnime_SetUpdate(Skel *);
void SkelAnime_InterpFrameTable(u8, s32, s32, s32, f32);
s32 SkelAnime_Morph(Skel *s) {
    f32 w = s->weight;
    s->weight = w - s->rate * D_801C9E1C;
    if (s->weight <= 0.0f) {
        SkelAnime_SetUpdate(s);
        s->weight = 0.0f;
    }
    SkelAnime_InterpFrameTable(s->limbCount, s->u20, s->u20, s->u24, 1.0f - s->weight / w);
    return 0;
}
