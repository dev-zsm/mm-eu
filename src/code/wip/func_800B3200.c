#include "types.h"
typedef struct { u8 pad0[0x64]; f32 x, y, z; } Actor;
extern u8 D_801AF344;
extern u8 D_801AF345;
extern u8 D_801AF346;
extern u8 D_801AF348;
extern u8 D_801AF349;
extern u8 D_801AF34A;
extern void EffectSsFireTail_Spawn(void *, Actor *, void *, f32, s32, s32, void *, void *, s32, s16, s32);

void EffectSsFireTail_SpawnFlame(void *play, Actor *actor, void *pos, f32 scale, s16 arg4, f32 arg5) {
    s32 v;

    D_801AF346 = 0;
    v = 255.0f * arg5;
    D_801AF345 = v;
    D_801AF349 = 0;
    D_801AF34A = 0;
    D_801AF348 = v;
    D_801AF344 = v;
    EffectSsFireTail_Spawn(play, actor, pos, scale, (s32)&actor->x, 0xF, &D_801AF344, &D_801AF348, (arg5 == 1.0f) ? 0 : 1, arg4, 1);
}
