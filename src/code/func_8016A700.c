#include "types.h"

typedef struct {
    u8 pad0[0x800];
    void *cameras[4];
    s16 activeCamId;
} PlayState;

void func_800DE0B8(void *camera, s16 status);

void Play_ChangeCameraStatus(PlayState *play, s16 camId, s16 status) {
    s16 id;

    if (camId == -1) {
        id = play->activeCamId;
    } else {
        id = camId;
    }
    if (status == 7) {
        play->activeCamId = id;
    }
    func_800DE0B8(play->cameras[id], status);
}
