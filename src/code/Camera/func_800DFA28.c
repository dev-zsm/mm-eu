#include "types.h"
#include "generated/code_funcs.h"

typedef struct {
    s16 pitch;
    s16 yaw;
} Dir;

extern void Camera_GetInputDir(Dir *out, s32 arg1);

s16 Camera_GetInputDirYaw(struct Camera *camera) {
    s32 pad; // Pads the frame so that dir lands at sp+0x18.
    Dir dir;

    Camera_GetInputDir(&dir, camera);
    return dir.yaw;
}
