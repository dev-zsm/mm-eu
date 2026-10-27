// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern void Camera_GetCamDir();

s16 Camera_GetCamDirPitch(s32 a0) {
    s32 pad;
    s32 sp18;

    Camera_GetCamDir(&sp18, a0);
    return *(s16 *)&sp18;
}
