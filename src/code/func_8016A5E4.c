// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
// -r4300_mul: the ROM has a nop after the mul.s that precedes the next mul.s
#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

void Actor_GetProjectedPos(void *play, Vec3f *worldPos, Vec3f *projectedPos, f32 *invW);

void Play_GetScreenPos(void *play, Vec3f *worldPos, Vec3f *screenPos) {
    f32 invW;

    Actor_GetProjectedPos(play, worldPos, screenPos, &invW);
    screenPos->x = (screenPos->x * invW * 160.0f) + 160.0f;
    screenPos->y = 120.0f - (screenPos->y * invW * 120.0f);
}
