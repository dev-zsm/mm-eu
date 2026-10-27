#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

typedef struct {
    u8 pad0[0x18];
    s32 unk18;
} BgPoly;

extern void func_800CA7A4(s32 a, s32 b, s32 c, s32 d, Vec3f *out);

Vec3f Camera_BgCheckCorner(s32 arg1, s32 arg2, BgPoly *polyA, BgPoly *polyB) {
    Vec3f corner;

    func_800CA7A4(polyA->unk18, polyB->unk18, arg1, arg2, &corner);
    return corner;
}
