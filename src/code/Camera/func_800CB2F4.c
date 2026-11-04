#include "types.h"

typedef struct {
    u8 pad0[0xC0];
    f32 unkC0;
    f32 unkC4;
    f32 unkC8;
    f32 unkCC;
    f32 unkD0;
    f32 unkD4;
} Camera;

extern f32 D_801D4E54;

void Camera_SetUpdateRatesFastPitch(Camera *camera) {
    f32 rate = D_801D4E54;

    camera->unkCC = rate;
    camera->unkD0 = rate;
    camera->unkD4 = rate;
    camera->unkC8 = 100.0f;
    camera->unkC4 = 16.0f;
    camera->unkC0 = 20.0f;
}
