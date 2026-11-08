// FLAGS: -O2 -g3 -mips2
#include "types.h"

void EffectSsFireTail_SpawnFlame(void *a0, void *a1, void *a2, f32 a3, s32 a4, f32 a5);

void EffectSsFireTail_SpawnFlameOnPlayer(struct PlayState *play, f32 scale, s16 bodyPart, f32 colorIntensity) {
    u8 *p = *(u8 **)((u8 *)play + 0x1CCC);
    EffectSsFireTail_SpawnFlame(play, p, (u8 *)((s32)p + bodyPart * 0xC + 0xBEC), scale, bodyPart, colorIntensity);
}
