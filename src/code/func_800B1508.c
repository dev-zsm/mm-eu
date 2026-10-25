#include "types.h"

extern void EffectSsDust_Spawn(void *play, s32 type, void *pos, void *velocity, void *accel, s32 a5, s32 a6, s16 a7,
                               s16 a8, s32 a9, s32 a10);

void func_800B1508(void *play, void *pos, void *velocity, void *accel, s32 a4, s32 a5, s16 a6, s16 a7) {
    EffectSsDust_Spawn(play, 0, pos, velocity, accel, a4, a5, a6, a7, 10, 1);
}
