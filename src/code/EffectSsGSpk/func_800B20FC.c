#include "types.h"

typedef struct { f32 x, y, z; } Vec3f;
typedef struct { u8 r, g, b, a; } Color;

void Math_Vec3f_Copy(Vec3f *dst, Vec3f *src);
void Color_RGBA8_Copy(Color *dst, Color *src);
void EffectSs_Spawn(s32 globalCtx, s32 type, s32 priority, void *init);

void EffectSsGSpk_SpawnNoAccel(s32 globalCtx, s32 actor, Vec3f *pos, Vec3f *velocity, Vec3f *accel, Color *prim,
                               Color *env, s16 scale, s16 scaleStep) {
    struct {
        s32 actor;
        Vec3f pos;
        Vec3f velocity;
        Vec3f accel;
        Color prim;
        Color env;
        s16 scale;
        s16 scaleStep;
        u8 flag;
    } init;

    Math_Vec3f_Copy(&init.pos, pos);
    Math_Vec3f_Copy(&init.velocity, velocity);
    Math_Vec3f_Copy(&init.accel, accel);
    Color_RGBA8_Copy(&init.prim, prim);
    Color_RGBA8_Copy(&init.env, env);
    init.actor = actor;
    init.scale = scale;
    init.scaleStep = scaleStep;
    init.flag = 1;
    EffectSs_Spawn(globalCtx, 5, 0x80, &init);
}
