#include "types.h"

extern s16 Animation_GetLastFrame(void *anim);
extern void Animation_Change(void *skelAnime, void *anim, f32 playSpeed, f32 startFrame, f32 endFrame, u8 mode,
                             f32 morphFrames);

void Animation_PlayLoopSetSpeed(void *skelAnime, void *anim, f32 playSpeed) {
    Animation_Change(skelAnime, anim, playSpeed, 0.0f, Animation_GetLastFrame(anim), 0, 0.0f);
}
