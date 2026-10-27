#include "types.h"

typedef struct {
    u8 pad0[0x12];
    s16 unk12;
} AnimHeader;

typedef struct {
    u8 pad0[0x18];
    void *unk18;
} FlexSkeleton;

extern AnimHeader *func_80100304(void *anim);
extern void Keyframe_FlexChangeAnim(FlexSkeleton *skel, void *dst, void *anim, f32 a3, f32 a4, f32 a5, f32 a6, f32 a7, s32 a8);

void Keyframe_FlexMorphToPlayLoop(FlexSkeleton *skel, void *anim, f32 morphFrames) {
    Keyframe_FlexChangeAnim(skel, skel->unk18, anim, 1.0f, func_80100304(anim)->unk12, 1.0f, 1.0f, morphFrames, 1);
}
