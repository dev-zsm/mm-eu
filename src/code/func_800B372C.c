#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

typedef struct {
    Vec3f a;
    Vec3f b;
    Vec3f c;
    s16 value;
} EffectParams;

extern void Math_Vec3f_Copy(Vec3f *dst, Vec3f *src);
extern void EffectSs_Spawn(void *arg0, s32 arg1, s32 arg2, void *arg3);

void func_800B372C(void *arg0, Vec3f *arg1, Vec3f *arg2, Vec3f *arg3, s16 arg4) {
    EffectParams params;

    Math_Vec3f_Copy(&params.a, arg1);
    Math_Vec3f_Copy(&params.b, arg2);
    Math_Vec3f_Copy(&params.c, arg3);
    params.value = arg4;
    EffectSs_Spawn(arg0, 0x24, 0x80, &params);
}
