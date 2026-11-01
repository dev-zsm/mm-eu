#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3f_800CBED8;

typedef struct {
    /* 0x00 */ u8 pad0[0x8C];
    /* 0x8C */ u8 *unk8C;
} Camera_800CBED8;

extern s32 BgCheck_CameraLineTest1(void *, s32, Vec3f_800CBED8 *, Vec3f_800CBED8 *, s32 *, s32, s32, s32, s32, s32 *);

s32 Camera_BgCheck(Camera_800CBED8 *arg0, s32 arg1, Vec3f_800CBED8 *arg2) {
    s32 pad;
    Vec3f_800CBED8 sp38;
    s32 sp34;
    s32 sp30;

    sp30 = 0;
    if (BgCheck_CameraLineTest1(arg0->unk8C + 0x830, arg1, arg2, &sp38, &sp30, 1, 1, 1, -1, &sp34) != 0) {
        *arg2 = sp38;
        return 1;
    }
    return 0;
}
