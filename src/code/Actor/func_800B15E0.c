#include "types.h"

extern u8 D_801AF270[];
extern u8 D_801AF274[];

extern void EffectSsDust_Spawn(void *play, s32 type, void *pos, void *velocity, void *accel, void *a5, void *a6,
                               s32 a7, s32 a8, s32 a9, s32 a10);

void func_800B15E0(void *play, void *pos, void *velocity, void *accel) {
    EffectSsDust_Spawn(play, 4, pos, velocity, accel, D_801AF270, D_801AF274, 100, 5, 10, 0);
}
