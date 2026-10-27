#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

typedef struct {
    u8 pad0[0x128];
    Vec3f distortionOrientation;
    Vec3f distortionScale;
    f32 distortionSpeed;
} View;

s32 View_SetDistortion(View *view, Vec3f orientation, Vec3f scale, f32 speed) {
    view->distortionOrientation = orientation;
    view->distortionScale = scale;
    view->distortionSpeed = speed;
    return 1;
}
