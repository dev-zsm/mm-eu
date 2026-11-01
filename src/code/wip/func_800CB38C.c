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

extern f32 D_801D4E60;

void Camera_SetUpdateRatesSlow(Camera *arg0) {
    f32 a = 1800.0f;
    f32 b = D_801D4E60;

    arg0->unkC0 = a;
    arg0->unkC8 = a;
    arg0->unkC4 = a;
    arg0->unkCC = b;
    arg0->unkD0 = b;
    arg0->unkD4 = b;
}
