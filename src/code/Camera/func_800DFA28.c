#include "types.h"

typedef struct {
    s16 pitch;
    s16 yaw;
} Dir;

extern void Camera_GetInputDir(Dir *out, s32 arg1);

s16 Camera_GetInputDirYaw(s32 arg0) {
    s32 pad; // Pads the frame so that dir lands at sp+0x18.
    Dir dir;

    Camera_GetInputDir(&dir, arg0);
    return dir.yaw;
}
