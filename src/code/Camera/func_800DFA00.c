// FLAGS: -O2 -g3 -mips2
#include "types.h"
typedef struct { s16 x; s16 y; s16 z; } Vec3s;
extern void Camera_GetInputDir();
s16 Camera_GetInputDirPitch(s32 a0) {
    Vec3s dir;
    Camera_GetInputDir(&dir, a0);
    return dir.x;
}
