// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0xA2];
    u8 speedIdx;
} Play;

typedef struct {
    u8 pad0[0x10];
    f32 endFrame;
    f32 pad14;
    f32 curFrame;
    f32 playSpeed;
} Anim;

extern void PlayerAnimation_AnimateFrame(f32 a, f32 b);

s32 PlayerAnimation_Once(Play *play, Anim *anim) {
    f32 end = anim->endFrame;
    f32 spd = (s32)play->speedIdx * 0.5f;
    f32 t;
    f32 c = anim->curFrame;

    if (end == c) {
        PlayerAnimation_AnimateFrame(end, spd);
        return 1;
    }
    anim->curFrame = anim->curFrame + anim->playSpeed * spd;
    if ((anim->curFrame - end) * anim->playSpeed > 0.0f) {
        anim->curFrame = end;
    } else if (anim->curFrame < 0.0f) {
        anim->curFrame = anim->curFrame + anim->pad14;
    } else {
        t = anim->pad14;
        if (t <= anim->curFrame) {
            anim->curFrame = anim->curFrame - t;
        }
    }
    PlayerAnimation_AnimateFrame(end, spd);
    return 0;
}
