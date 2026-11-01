// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

extern s32 D_801AF33C;
extern s32 D_801AF340;

void func_800B3064(s32 a0, s32 a1, s32 a2, f32 a3) {
    EffectSsEnIce_SpawnFlying(a0, a1, a2, &D_801AF33C, &D_801AF340, a3);
}
