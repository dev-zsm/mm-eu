#include "types.h"

typedef struct { f32 x, y, z; } Vec3f;
typedef struct {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ f32 scale;
    /* 0x14 */ Vec3f vel;
    /* 0x20 */ Vec3f accel;
    /* 0x2C */ u8 primColor[4];
    /* 0x30 */ u8 envColor[4];
    /* 0x34 */ s32 life;
    /* 0x38 */ s16 type;
} IceInit;

extern void Math_Vec3f_Copy(Vec3f *dst, Vec3f *src);
extern void Color_RGBA8_Copy(u8 *dst, u8 *src);
extern void EffectSs_Spawn(void *play, s32 a, s32 b, IceInit *init);

void EffectSsEnIce_Spawn(void *play, Vec3f *pos, f32 scale, Vec3f *vel, Vec3f *accel, u8 *prim, u8 *env, s32 life) {
    IceInit init;

    Math_Vec3f_Copy(&init.pos, pos);
    Math_Vec3f_Copy(&init.vel, vel);
    Math_Vec3f_Copy(&init.accel, accel);
    Color_RGBA8_Copy(init.primColor, prim);
    Color_RGBA8_Copy(init.envColor, env);
    init.scale = scale;
    init.life = life;
    init.type = 1;
    EffectSs_Spawn(play, 0x1B, 0x80, &init);
}
