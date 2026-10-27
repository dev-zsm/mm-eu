#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3f_800BE0C0;

typedef struct {
    s16 pitch;
    s16 yaw;
} Angles_800BE0C0;

extern s16 Math_Atan2S_XY(f32, f32);
float sqrtf(float);
#pragma intrinsic (sqrtf)

void func_800BE0C0(Vec3f_800BE0C0 *arg0, Vec3f_800BE0C0 *arg1, Angles_800BE0C0 *arg2, s32 arg3) {
    f32 dx;
    f32 dz;
    f32 dy;

    dx = arg1->x - arg0->x;
    dz = arg1->z - arg0->z;
    if (arg3 != 0) {
        dy = arg1->y - arg0->y;
    } else {
        dy = arg0->y - arg1->y;
    }
    arg2->yaw = Math_Atan2S_XY(dz, dx);
    arg2->pitch = Math_Atan2S_XY(sqrtf(dx * dx + dz * dz), dy);
}
