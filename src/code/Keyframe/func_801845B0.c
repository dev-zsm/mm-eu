// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x12];
    s16 unk12;
} Anim45;

Anim45 *func_80100304(s32);
void Keyframe_FlexChangeAnim(void *, s32, s32, f32, f32, f32, f32, f32, s32);

void Keyframe_FlexPlayOnceSetSpeed(struct KFSkelAnimeFlex *kfSkelAnime, struct KeyFrameAnimation *animation, f32 speed) {
    Keyframe_FlexChangeAnim(kfSkelAnime, *(s32 *)((u8 *)kfSkelAnime + 0x18), animation, 1.0f, (f32) func_80100304(animation)->unk12, 1.0f, speed, 0.0f, 0);
}
