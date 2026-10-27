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
    u8 pad4B;
    s16 unk4C;
    s16 pad4E;
    s32 unk50;
    u8 pad54[8];
    u8 unk5C;
} DeadDdParams;
extern void Math_Vec3f_Copy(Vec3f *, Vec3f *);
extern void EffectSs_Spawn(void *, s32, s32, void *);

void EffectSsDeadDd_Spawn(void *play, Vec3f *pos, Vec3f *velocity, Vec3f *accel, Color_RGBA8 *prim, Color_RGBA8 *env, s16 scale, s16 scaleStep, s16 unk4C, s32 unk50) {
    DeadDdParams p;

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
    p.unk5C = 0;
    p.unk4C = unk4C;
    p.unk50 = unk50;
    EffectSs_Spawn(play, 0x21, 0x78, &p);
}
