#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

extern Vec3f D_801AF2A0;
extern u8 D_801C9EE0[];

extern void EffectSsHahen_Spawn(void *play, void *pos, void *velocity, void *accel, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8);

void func_800B2884(void *play, void *pos, s32 arg2) {
    Vec3f accel = D_801AF2A0;

    EffectSsHahen_Spawn(play, pos, D_801C9EE0, &accel, 1, 5, 1, 10, arg2);
}
