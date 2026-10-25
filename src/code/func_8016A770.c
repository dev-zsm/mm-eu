#include "types.h"

typedef struct {
    u8 pad0[0x800];
    void *cameraPtrs[4];
    s16 activeCamId;
} CameraPlay;

extern void func_800DE0B8(void *camera, s32 flags, CameraPlay *play);

void Play_ClearCamera(CameraPlay *play, s16 camId) {
    s16 id;

    if (camId == -1) {
        id = play->activeCamId;
    } else {
        id = camId;
    }
    if (play->cameraPtrs[id] != NULL) {
        func_800DE0B8(play->cameraPtrs[id], 0x100, play);
        play->cameraPtrs[id] = NULL;
    }
}
