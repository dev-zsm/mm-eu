#include "types.h"

typedef struct {
    u8 pad0[0x15A];
    s16 roll;
} Camera_8016AAF8;

typedef struct {
    u8 pad0[0x800];
    Camera_8016AAF8 *cameraPtrs[4];
    s16 activeCamId;
} Play_8016AAF8;

s32 Play_SetCameraRoll(Play_8016AAF8 *play, s16 camId, s16 roll) {
    s16 id;
    Camera_8016AAF8 *cam;

    if (camId == -1) {
        id = play->activeCamId;
    } else {
        id = camId;
    }
    cam = play->cameraPtrs[id];
    cam->roll = roll;
    return 1;
}
