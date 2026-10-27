#include "types.h"

typedef struct {
    f32 pos[3];
    s16 rot[3];
} PosRotB4B0;

typedef struct {
    u8 pad0[0x1CCC];
    void *unk1CCC;
} PlayB4B0;

typedef struct {
    u8 pad0[0x8C];
    PlayB4B0 *play;
    void *focalActor;
    u8 pad94[4];
    f32 unk98;
} CameraB4B0;

f32 func_800B6D4C(void *);
void Actor_GetFocus(PosRotB4B0 *, void *);

f32 Camera_GetFocalActorHeight(CameraB4B0 *camera) {
    PosRotB4B0 focus;
    f32 height;

    if (camera->play->unk1CCC == camera->focalActor) {
        height = func_800B6D4C(camera->focalActor);
    } else {
        Actor_GetFocus(&focus, camera->focalActor);
        height = focus.pos[1] - camera->unk98;
        if (height == 0.0f) {
            height = 10.0f;
        }
    }
    return height;
}
