#include "types.h"

extern s32 Animation_GetLastFrame(void *animation);
extern void Animation_Change(void *skelAnime, void *animation, f32 playSpeed, f32 startFrame, f32 endFrame, s32 mode,
                             f32 morphFrames);

void Animation_PlayOnceSetSpeed(void *skelAnime, void *animation, f32 playSpeed) {
    Animation_Change(skelAnime, animation, playSpeed, 0.0f, (f32)Animation_GetLastFrame(animation), 2, 0.0f);
}
