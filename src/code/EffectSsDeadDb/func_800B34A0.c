#include "types.h"
typedef struct { f32 x, y, z; } Vec3f;
typedef struct { u8 r, g, b, a; } Color_RGBA8;
typedef struct {
    Vec3f pos;
    Vec3f velocity;
    Vec3f accel;
    s16 scale;
    s16 scaleStep;
    u8 prim[4];
    u8 env[3];
    s32 unk;
} DeadDbParams;
extern void Math_Vec3f_Copy(Vec3f *, Vec3f *);
extern void EffectSs_Spawn(void *, s32, s32, void *);

void EffectSsDeadDb_Spawn(void *play, Vec3f *pos, Vec3f *velocity, Vec3f *accel, Color_RGBA8 *prim, Color_RGBA8 *env, s16 scale, s16 scaleStep, s32 unk) {
    DeadDbParams p;

    Math_Vec3f_Copy(&p.pos, pos);
    Math_Vec3f_Copy(&p.velocity, velocity);
    Math_Vec3f_Copy(&p.accel, accel);
    p.scale = scale;
    p.scaleStep = scaleStep;
    p.prim[0] = prim->r;
    p.prim[1] = prim->g;
    p.prim[2] = prim->b;
    p.prim[3] = prim->a;
    p.env[0] = env->r;
    p.env[1] = env->g;
    p.env[2] = env->b;
    p.unk = unk;
    EffectSs_Spawn(play, 0x20, 0x78, &p);
}
