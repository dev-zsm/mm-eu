#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

typedef struct {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ Vec3f velocity;
    /* 0x18 */ Vec3f accel;
    /* 0x24 */ s16 unk24;
    /* 0x26 */ s16 unk26;
    /* 0x28 */ u8 unk28;
} EffectSsBomb2InitParams;

void Math_Vec3f_Copy(Vec3f *dest, Vec3f *src);
void EffectSs_Spawn(void *play, s32 type, s32 priority, void *initParams);

void EffectSsBomb2_SpawnLayered(void *play, Vec3f *pos, Vec3f *velocity, Vec3f *accel, s16 arg4, s16 arg5) {
    EffectSsBomb2InitParams initParams;

    Math_Vec3f_Copy(&initParams.pos, pos);
    Math_Vec3f_Copy(&initParams.velocity, velocity);
    Math_Vec3f_Copy(&initParams.accel, accel);
    initParams.unk24 = arg4;
    initParams.unk26 = arg5;
    initParams.unk28 = 1;
    EffectSs_Spawn(play, 3, 10, &initParams);
}
