#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

void func_800CBA34(s32 arg0, s32 arg1, Vec3f *vec);

void func_800CBD54(s32 arg0, s32 arg1, Vec3f *vec) {
    s32 pad1[7]; // padding so the frame matches
    Vec3f tmp;
    s32 pad2;

    tmp = *vec;
    func_800CBA34(arg0, arg1, &tmp);
    *vec = tmp;
}
