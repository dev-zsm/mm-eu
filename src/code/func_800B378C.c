#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

typedef struct {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ Vec3f velocity;
    /* 0x1C */ Vec3f accel;
    /* 0x28 */ s16 unk28;
} EffectSsInitParams;

void Math_Vec3f_Copy(Vec3f *dest, Vec3f *src);
void EffectSs_Spawn(void *play, s32 type, s32 priority, void *initParams);

void func_800B378C(void *play, Vec3f *pos, Vec3f *velocity, Vec3f *accel, s16 arg4) {
    EffectSsInitParams initParams;

    Math_Vec3f_Copy(&initParams.pos, pos);
    Math_Vec3f_Copy(&initParams.velocity, velocity);
    Math_Vec3f_Copy(&initParams.accel, accel);
    initParams.unk28 = arg4;
    EffectSs_Spawn(play, 0x25, 0x80, &initParams);
}
