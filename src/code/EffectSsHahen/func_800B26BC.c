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
    /* 0x24 */ void *dList;
    /* 0x28 */ s16 unk28;
    /* 0x2A */ s16 unk2A;
    /* 0x2C */ s16 unk2C;
    /* 0x2E */ s16 unk2E;
} EffectSsHahenInitParams; /* size = 0x30 */

extern void Math_Vec3f_Copy(Vec3f *, Vec3f *);
extern void EffectSs_Spawn(void *, s32, s32, void *);

void EffectSsHahen_Spawn(void *play, Vec3f *pos, Vec3f *velocity, Vec3f *accel, s16 arg4, s16 arg5, s16 arg6,
                         s16 arg7, void *dList) {
    EffectSsHahenInitParams initParams;

    Math_Vec3f_Copy(&initParams.pos, pos);
    Math_Vec3f_Copy(&initParams.velocity, velocity);
    Math_Vec3f_Copy(&initParams.accel, accel);
    initParams.dList = dList;
    initParams.unk28 = arg4;
    initParams.unk2A = arg5;
    initParams.unk2C = arg6;
    initParams.unk2E = arg7;
    EffectSs_Spawn(play, 0xF, 0x80, &initParams);
}
