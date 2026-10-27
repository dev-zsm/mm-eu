#include "types.h"

void Animation_Change(s32 a0, s32 a1, s32 a2, f32 a3, f32 a4, s32 a5, f32 a6);

void Animation_MorphToLoop(s32 a0, s32 a1, f32 a2) {
    Animation_Change(a0, a1, 0x3F800000, 0.0f, 0.0f, 0, a2);
}
