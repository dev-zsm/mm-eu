#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

typedef struct {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ Vec3f velocity;
    /* 0x1C */ Vec3f accel;
    /* 0x28 */ s32 unk28;
} EffectSsIcePieceInitParams;

void Math_Vec3f_Copy(Vec3f *dest, Vec3f *src);
void EffectSs_Spawn(void *play, s32 type, s32 priority, void *initParams);

void EffectSsIcePiece_Spawn(void *play, Vec3f *pos, f32 arg2, Vec3f *velocity, Vec3f *accel, s32 arg5) {
    EffectSsIcePieceInitParams initParams;

    Math_Vec3f_Copy(&initParams.pos, pos);
    Math_Vec3f_Copy(&initParams.velocity, velocity);
    Math_Vec3f_Copy(&initParams.accel, accel);
    initParams.unkC = arg2;
    initParams.unk28 = arg5;
    EffectSs_Spawn(play, 0x1A, 0x80, &initParams);
}
