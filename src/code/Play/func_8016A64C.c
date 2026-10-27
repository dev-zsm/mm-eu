#include "types.h"

typedef struct {
    /* 0x000 */ u8 pad0[0x164];
    /* 0x164 */ s16 unk164;
    /* 0x166 */ u8 pad166[0x12];
} Cam; /* size 0x178 */

typedef struct {
    /* 0x000 */ u8 pad0[0xB8];
    /* 0x0B8 */ u8 unkB8[0x168];
    /* 0x220 */ Cam cams[4];
    /* 0x800 */ Cam *camPtrs[4];
    /* 0x810 */ u8 pad810[0x20];
    /* 0x830 */ u8 unk830[1];
} Play;

void Camera_Init(Cam *cam, void *a, void *b);

s16 Play_CreateSubCamera(Play *play) {
    s16 i;

    for (i = 1; i < 4; i++) {
        if (play->camPtrs[i] == 0) {
            break;
        }
    }
    if (i == 4) {
        return -1;
    }
    play->camPtrs[i] = &play->cams[i];
    Camera_Init(play->camPtrs[i], play->unkB8, play->unk830);
    play->camPtrs[i]->unk164 = i;
    return i;
}
