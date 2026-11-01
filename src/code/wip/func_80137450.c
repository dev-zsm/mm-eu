#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[0xC];
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 pad14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C;
} Skel;

extern f32 D_801C9E1C;
extern void SkelAnime_AnimateFrame(Skel *);

s32 SkelAnime_LoopPartial(Skel *a0) {
    f32 t;
    a0->unk18 += a0->unk1C * D_801C9E1C;
    t = a0->unk18;
    if (t < a0->unkC) {
        a0->unk18 = a0->unk10 + (t - a0->unkC);
    } else if (a0->unk10 <= t) {
        a0->unk18 = a0->unkC + (t - a0->unk10);
    }
    SkelAnime_AnimateFrame(a0);
    return 0;
}
