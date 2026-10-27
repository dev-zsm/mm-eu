#include "types.h"

typedef struct { void *anim; f32 playSpeed; f32 startFrame; f32 endFrame; u8 mode; f32 morph; } AnimInfo;

extern s32 Animation_GetLastFrame(void *anim);
extern void Animation_Change(void *skel, void *anim, f32 a, f32 b, f32 c, s32 mode, f32 morph);

void Actor_ChangeAnimationByInfo(void *skel, AnimInfo *info, s32 idx) {
    f32 end;
    f32 arg;

    info += idx;
    end = info->endFrame;
    if (end > 0.0f) {
        arg = end;
    } else {
        arg = Animation_GetLastFrame(info->anim);
    }
    Animation_Change(skel, info->anim, info->playSpeed, info->startFrame, arg, info->mode, info->morph);
}
