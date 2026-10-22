// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct { s16 x; s16 y; s16 z; } Vec3s;
void Camera_GetCamDir(Vec3s *, s32);

s16 Camera_GetCamDirYaw(s32 arg0) {
    Vec3s sp18;

    Camera_GetCamDir(&sp18, arg0);
    return sp18.y;
}
