#include "types.h"

typedef struct {
    u8 pad0[0x8C];
    struct {
        u8 pad0[0x1CCC];
        s32 unk1CCC;
    } *unk8C;
    s32 unk90;
    u8 unk94[0xCA];
    s16 unk15E;
} CameraFocus;

extern void Actor_GetWorldPosShapeRot(void *a);
extern void Actor_GetWorld(void *a, s32 b);

void Camera_SetFocalActor(CameraFocus *camera, s32 focalActor) {
    camera->unk90 = focalActor;
    if (focalActor == camera->unk8C->unk1CCC) {
        Actor_GetWorldPosShapeRot(camera->unk94);
    } else {
        Actor_GetWorld(camera->unk94, camera->unk90);
    }
    camera->unk15E = 0;
}
