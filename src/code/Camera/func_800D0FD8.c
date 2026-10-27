// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x148];
    s16 unk148;
    u8 pad14a[0x10];
    s16 unk15A;
    u8 pad15c[2];
    s16 unk15E;
} Camera;

typedef struct {
    u8 pad0[0xA];
    s16 unkA;
} CamPoint;

CamPoint *Camera_GetBgCamOrActorCsCamFuncData(Camera *, s16);
s16 Camera_ScaledStepToCeilS(s16, s16, s32, s32);
void Camera_Normal1(Camera *);
extern s16 D_801E5470;

s32 Camera_Normal4(Camera *arg0) {
    s32 pad;
    s16 sp22;

    if ((arg0->unk15E == 0) || (arg0->unk15E == 0xA) || (arg0->unk15E == 0x14)) {
        D_801E5470 = Camera_GetBgCamOrActorCsCamFuncData(arg0, arg0->unk148)->unkA;
    }
    sp22 = arg0->unk15A;
    Camera_Normal1(arg0);
    arg0->unk15A = Camera_ScaledStepToCeilS(D_801E5470, sp22, 0x3D4CCCCD, 5);
    return 1;
}
