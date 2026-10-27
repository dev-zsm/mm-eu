#include "types.h"

typedef struct {
    u8 pad0[0x12];
    s16 frameCount;
} KeyFrameAnimHeader;

typedef struct {
    u8 pad0[0x18];
    void *unk18;
} KFSkelAnime;

KeyFrameAnimHeader *func_80100304(void *anim);
void Keyframe_StandardChangeAnim(KFSkelAnime *kfSkelAnime, void *skel, void *anim, f32 startFrame, f32 endFrame, f32 playSpeed,
                   f32 unk, f32 morphFrames, s32 mode, s32 arg9);

void Keyframe_StandardMorphToPlayLoop(KFSkelAnime *kfSkelAnime, void *anim, s32 arg2, f32 morphFrames) {
    Keyframe_StandardChangeAnim(kfSkelAnime, kfSkelAnime->unk18, anim, 1.0f, func_80100304(anim)->frameCount, 1.0f, 1.0f, morphFrames,
                  1, arg2);
}
