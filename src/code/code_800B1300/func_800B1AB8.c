#include "types.h"

typedef struct { f32 x, y, z; } Vec3f;

void func_800B18F8(s32 a0, f32 a1, Vec3f *a2, Vec3f *a3, Vec3f *a4);
void func_800B1810(s32 play, Vec3f *a1, Vec3f *a2, Vec3f *a3, s32 a4, s32 a5, s32 a6);

void func_800B1AB8(s32 play, f32 arg1, s32 arg2) {
    s32 i;
    Vec3f c;
    Vec3f b;
    Vec3f a;

    for (i = 0; i < 20; i++) {
        func_800B18F8(arg2, arg1, &c, &b, &a);
        func_800B1810(play, &c, &b, &a, 100, 30, 7);
    }
}
