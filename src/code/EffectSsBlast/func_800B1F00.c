#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3f_800B1F00;

extern void Math_Vec3f_Copy(Vec3f_800B1F00 *, Vec3f_800B1F00 *);
extern void Color_RGBA8_Copy(void *, void *);
extern void EffectSs_Spawn(void *, s32, s32, void *);

void EffectSsBlast_Spawn(void *arg0, Vec3f_800B1F00 *arg1, Vec3f_800B1F00 *arg2, Vec3f_800B1F00 *arg3, void *arg4, void *arg5,
                         s16 arg6, s16 arg7, s16 arg8, s16 arg9) {
    struct {
        Vec3f_800B1F00 pos;
        Vec3f_800B1F00 vel;
        Vec3f_800B1F00 accel;
        u8 c1[4];
        u8 c2[4];
        s16 a, b, c, d;
    } init;

    Math_Vec3f_Copy(&init.pos, arg1);
    Math_Vec3f_Copy(&init.vel, arg2);
    Math_Vec3f_Copy(&init.accel, arg3);
    Color_RGBA8_Copy(init.c1, arg4);
    Color_RGBA8_Copy(init.c2, arg5);
    init.a = arg6;
    init.b = arg7;
    init.c = arg8;
    init.d = arg9;
    EffectSs_Spawn(arg0, 4, 0x80, &init);
}
