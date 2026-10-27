#include "types.h"

typedef struct {
    u8 pad0[0x12];
    s16 frameCount;
} AnimHeader;

typedef struct {
    u8 pad0[0x18];
    void *skeleton;
} Keyframe;

extern AnimHeader *func_80100304(s32 segAddr);
extern void Keyframe_FlexChangeAnim(Keyframe *kf, void *skeleton, s32 anim, f32 a3, f32 a4, f32 a5, f32 a6, f32 a7,
                                    s32 a8);

void Keyframe_FlexMorphToPlayOnce(Keyframe *kf, s32 anim, f32 morphFrames) {
    Keyframe_FlexChangeAnim(kf, kf->skeleton, anim, 1.0f, func_80100304(anim)->frameCount, 1.0f, 1.0f, morphFrames, 0);
}
