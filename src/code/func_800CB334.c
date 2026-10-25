// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0xC0];
    f32 unkC0;
    f32 unkC4;
    f32 unkC8;
    f32 unkCC;
    f32 unkD0;
    f32 unkD4;
    u8 padD8[8];
    f32 unkE0;
} Camera;
void Camera_SetUpdateRatesFastYaw(Camera *camera) {
    camera->unkC0 = 50.0f;
    camera->unkC8 = 50.0f;
    camera->unkCC = 0.01f;
    camera->unkC4 = 100.0f;
    camera->unkD0 = 0.1f;
    camera->unkD4 = 0.01f;
    if (camera->unkE0 > 1.0f) {
        camera->unkE0 = 1.0f;
    }
}
