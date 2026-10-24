// FLAGS: -O2 -g3 -mips2
#include "types.h"

void EffectSsHitmark_Spawn(s32, s32, s16);

void EffectSsHitmark_SpawnCustomScale(s32 a0, s32 a1, s16 a2) {
    EffectSsHitmark_Spawn(a0, a1, a2);
}
