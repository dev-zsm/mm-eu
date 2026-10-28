#include "types.h"

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;
typedef struct {
    s32 unk0;
    s32 unk4;
} Path;
extern Vec3s *func_80100304(s32);
extern f32 func_80180F74(f32, f32);
f32 SubS_GetDistSqAndOrientPath(Path *a0, s32 a1, f32 *a2, f32 *a3) {
    f32 dx = 0.0f;
    f32 dz = 0.0f;
    Vec3s *pts;
    Vec3s *pt;
    if (a0 != 0) {
        pts = func_80100304(a0->unk4);
        pt = &pts[a1];
        dx = pt->x - a2[0];
        dz = pt->z - a2[2];
    }
    if (((!a2) && (!a2)) && (!a2)) {
    }
    *a3 = (dx * dx) + (dz * dz);
    return func_80180F74(dx, dz);
}
