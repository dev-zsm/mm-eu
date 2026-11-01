// FLAGS: -O2 -g3 -mips2
#include "types.h"

void EffectSsKirakira_SpawnDispersed(s32, s32, s32, s32, s32, s32, s32, s32);

void EffectSsKirakira_SpawnSmall(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    EffectSsKirakira_SpawnDispersed(a0, a1, a2, a3, a4, a5, 0x3E8, 0x10);
}
