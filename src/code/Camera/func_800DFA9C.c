// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

typedef struct { s16 x; s16 y; s16 z; } Vec3s;

s16 Camera_GetCamDirYaw(struct Camera *camera) {
    Vec3s sp18;

    Camera_GetCamDir(&sp18, camera);
    return sp18.y;
}
