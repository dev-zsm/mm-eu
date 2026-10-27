#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[0x18];
    /* 0x18 */ void *unk18;
} KFSkelAnime;

typedef struct {
    /* 0x00 */ u8 pad0[0x12];
    /* 0x12 */ s16 unk12;
} KFAnimHeader;

extern KFAnimHeader *func_80100304(void *);
extern void Keyframe_StandardChangeAnim(KFSkelAnime *, void *, void *, f32, f32, f32, f32, f32, s32, s32);

void Keyframe_StandardMorphToPlayOnce(KFSkelAnime *kfSkel, void *anim, s32 arg2, f32 morphFrames) {
    Keyframe_StandardChangeAnim(kfSkel, kfSkel->unk18, anim, 1.0f, func_80100304(anim)->unk12, 1.0f, 1.0f, morphFrames, 0, arg2);
}
