#include "types.h"

typedef struct {
    u8 pad0[0x800];
    s32 unk800[1];
    u8 pad804[0xC];
    s16 unk810;
} CameraSub;

typedef struct {
    u8 pad0[0x8C];
    CameraSub *unk8C;
    u8 pad90[0xD4];
    s16 unk164;
} Camera;

extern void Camera_SetStateFlag(Camera *camera, s32 arg1);

s32 Camera_SetFinishedFlag(Camera *camera) {
    s32 temp;
    CameraSub *sub;
    s32 idx;

    Camera_SetStateFlag(camera, 8);
    temp = camera->unk164;
    if (temp == 0) {
        sub = camera->unk8C;
        idx = sub->unk810;
        if (idx != 0) {
            Camera_SetStateFlag((Camera *)sub->unk800[idx], 8);
            return camera->unk8C->unk810;
        }
    }
    return temp;
}
