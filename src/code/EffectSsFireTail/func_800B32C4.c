// FLAGS: -O2 -g3 -mips2
#include "types.h"

void EffectSsFireTail_SpawnFlame(void *a0, void *a1, void *a2, f32 a3, s32 a4, f32 a5);

void EffectSsFireTail_SpawnFlameOnPlayer(u8 *arg0, f32 arg1, s16 arg2, f32 arg3) {
    u8 *p = *(u8 **)(arg0 + 0x1CCC);
    EffectSsFireTail_SpawnFlame(arg0, p, (u8 *)((s32)p + arg2 * 0xC + 0xBEC), arg1, arg2, arg3);
}
