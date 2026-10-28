#include "types.h"

typedef struct { s32 a; f32 speed; s16 start; s16 end; u8 mode; u8 padD; s16 morph; } AnimInfoS;
s32 Animation_GetLastFrame(s32 a);
void Animation_Change(s32 a, s32 b, f32 c, f32 d, f32 e, s32 f, f32 g);

s32 SubS_ChangeAnimationByInfoS(s32 skelAnime, AnimInfoS *info, s32 idx) {
    s32 frameCount;
    s32 start;
    s32 end;
    f32 speed;

    info += idx;
    end = info->end;
    if (end < 0) {
        end = Animation_GetLastFrame(info->a);
    }
    start = info->start;
    if (start >= end || start < 0) {
        return 0;
    }
    speed = info->speed;
    frameCount = end;
    if (speed < 0.0f) {
        end = start;
        start = frameCount;
    }
    Animation_Change(skelAnime, info->a, speed, start, end, info->mode, info->morph);
    return 1;
}
