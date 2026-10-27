#include "types.h"

extern s32 Animation_GetLastFrame(void *arg);
extern void Animation_Change(void *a0, void *a1, f32 a2, f32 a3, f32 a4, s32 a5, f32 a6);

void Animation_PlayLoop(void *skelAnime, void *animation) {
    Animation_Change(skelAnime, animation, 1.0f, 0.0f, (f32)Animation_GetLastFrame(animation), 0, 0.0f);
}
