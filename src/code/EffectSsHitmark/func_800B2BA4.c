// FLAGS: -O2 -g0 -mips2
#include "types.h"

void EffectSsHitmark_Spawn(s32 a0, s32 a1, s32 a2, s32 a3);

void EffectSsHitmark_SpawnFixedScale(s32 a0, s32 a1, s32 a2) {
    EffectSsHitmark_Spawn(a0, a1, 0x12C, a2);
}
