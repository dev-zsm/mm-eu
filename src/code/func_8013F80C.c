#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

typedef struct {
    /* 0x000 */ u8 pad0[0x128];
    /* 0x128 */ Vec3f distortionOrientation;
    /* 0x134 */ Vec3f distortionScale;
    /* 0x140 */ f32 distortionSpeed;
    /* 0x144 */ Vec3f curDistortionOrientation;
    /* 0x150 */ Vec3f curDistortionScale;
} ViewDistortion;

s32 View_InitDistortion(ViewDistortion *view) {
    view->distortionOrientation.x = 0.0f;
    view->distortionScale.x = 1.0f;
    view->distortionOrientation.y = 0.0f;
    view->distortionOrientation.z = 0.0f;
    view->distortionScale.y = 1.0f;
    view->distortionScale.z = 1.0f;
    view->curDistortionOrientation = view->distortionOrientation;
    view->curDistortionScale = view->distortionScale;
    view->distortionSpeed = 0.0f;
    return 1;
}
