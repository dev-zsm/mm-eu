#include "types.h"
typedef struct { u8 pad0[0x14]; f32 unk14; f32 unk18; f32 unk1C; } S;
extern f32 D_801C9E1C;
void SkelAnime_AnimateFrame();
s32 SkelAnime_LoopFull(S *s) {
    f32 d = D_801C9E1C;
    s->unk18 += s->unk1C * d;
    if (s->unk18 < 0.0f) {
        s->unk18 += s->unk14;
    } else if (s->unk14 <= s->unk18) {
        s->unk18 -= s->unk14;
    }
    SkelAnime_AnimateFrame();
    return 0;
}
