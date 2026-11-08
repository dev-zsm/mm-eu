// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 Animation_GetLastFrame(s32);
void Animation_Change(s32, s32, f32, f32, f32, s32, f32);

void Animation_PlayOnce(struct SkelAnime *skelAnime, struct AnimationHeader *animation) {
    f32 temp;

    temp = (f32) Animation_GetLastFrame(animation);
    Animation_Change(skelAnime, animation, 1.0f, 0.0f, temp, 2, 0.0f);
}
