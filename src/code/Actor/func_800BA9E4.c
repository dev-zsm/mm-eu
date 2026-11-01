// FLAGS: -O2 -g3 -mips2
#include "types.h"

void Actor_SpawnAsChildAndCutscene(void *, void *, s32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32);

void Actor_Spawn(void *a0, void *a1, s16 a2, f32 a3, f32 a4, f32 a5, s16 a6, s16 a7, s16 a8, s32 a9) {
    Actor_SpawnAsChildAndCutscene(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, -1, 0x3FF, 0);
}
