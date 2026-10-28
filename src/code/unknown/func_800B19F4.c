// FLAGS: -O2 -g3 -mips2
#include "types.h"
typedef struct { f32 x, y, z; } Vec3f;
extern void func_800B18F8(void *a, f32 f, Vec3f *b, Vec3f *c, Vec3f *d);
extern void func_800B17A0(void *a, Vec3f *b, Vec3f *c, Vec3f *d, s32 e, s32 f, s32 g);
void func_800B19F4(void *a0, f32 f, void *a2) {
    s32 i;
    Vec3f v2;
    Vec3f v1;
    Vec3f v0;
    for (i = 0; i < 20; i++) {
        func_800B18F8(a2, f, &v2, &v1, &v0);
        func_800B17A0(a0, &v2, &v1, &v0, 100, 30, 7);
    }
}
