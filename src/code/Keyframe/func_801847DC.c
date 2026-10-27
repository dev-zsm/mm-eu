#include "types.h"

typedef struct { u8 pad0[0x12]; s16 unk12; } Anim;
typedef struct {
    u8 pad0[0x18];
    void *skel;
    Anim *anim;
    u8 pad20[4];
    f32 unk24;
} Kf;

extern void *func_80100304(void *);
extern void FrameCtrl_SetProperties(Kf *kf, s32 a1, s32 a2, f32 a3, f32 a4, f32 a5, s32 a6);

void Keyframe_FlexChangeAnim(Kf *kf, void *skel, void *anim, s32 a3, s32 a4, f32 f1, f32 f2, f32 f3, s32 a8) {
    kf->unk24 = f3;
    if (skel != kf->skel) {
        kf->skel = func_80100304(skel);
    }
    kf->anim = func_80100304(anim);
    FrameCtrl_SetProperties(kf, a3, a4, kf->anim->unk12, f1, f2, a8);
}
