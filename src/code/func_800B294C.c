#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

typedef struct {
    Vec3f pos;
    Vec3f velocity;
    Vec3f accel;
    s16 unk40;
    s16 unk42;
    s16 unk44;
} SibukiInitParams;

extern void Math_Vec3f_Copy(Vec3f *dst, void *src);
extern void EffectSs_Spawn(void *play, s32 type, s32 priority, void *initParams);

void EffectSsSibuki_Spawn(void *play, void *pos, void *velocity, void *accel, s16 arg4, s16 arg5, s16 arg6) {
    SibukiInitParams params;

    Math_Vec3f_Copy(&params.pos, pos);
    Math_Vec3f_Copy(&params.velocity, velocity);
    Math_Vec3f_Copy(&params.accel, accel);
    params.unk40 = arg4;
    params.unk42 = arg5;
    params.unk44 = arg6;
    EffectSs_Spawn(play, 0x11, 0x80, &params);
}
