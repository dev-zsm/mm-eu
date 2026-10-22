// FLAGS: -O2 -g3 -mips2
#include "types.h"

void EffectSsGSpk_SpawnAccel(s32, s32, s32, s32, s32, s32, s32, s32, s32);

void EffectSsGSpk_SpawnSmall(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6) {
    EffectSsGSpk_SpawnAccel(a0, a1, a2, a3, a4, a5, a6, 0x64, 5);
}
