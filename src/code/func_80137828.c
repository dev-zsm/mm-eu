#include "types.h"

extern s32 Animation_GetLastFrame(void *a);
extern void Animation_Change(void *a, void *b, f32 c, f32 d, f32 e, s32 f, f32 g);

void Animation_MorphToPlayOnce(void *skelAnime, void *animation, f32 morphFrames) {
    Animation_Change(skelAnime, animation, 1.0f, 0.0f, (f32)Animation_GetLastFrame(animation), 2, morphFrames);
}
