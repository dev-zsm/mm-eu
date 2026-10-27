#include "types.h"
typedef struct {
    s32 unk0;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    u8 pad_c[0x142 - 0xC];
    s16 unk142;
    s16 unk144;
    u8 pad146[0x150 - 0x146];
    s16 unk150;
    u8 pad152[0x156 - 0x152];
    s16 unk156;
    u8 pad158[0x162 - 0x158];
    s16 unk162;
} Camera;
extern void Camera_ResetActionFuncState(Camera *c, s16 m);
extern void Camera_ChangeSettingFlags(Camera *c, s16 a, s16 b);
s32 Camera_ChangeDoorCam(Camera *camera, s32 a1, s16 a2, s32 a3, s16 a4, s16 a5, s16 a6) {
    if (camera->unk142 == 8) {
        return 0;
    }
    camera->unk0 = a1;
    camera->unk6 = a4;
    camera->unk8 = a5;
    camera->unk4 = a2;
    camera->unkA = a6;
    if (a2 == -99) {
        Camera_ResetActionFuncState(camera, camera->unk144);
        return -99;
    }
    if (a2 == -1) {
        Camera_ChangeSettingFlags(camera, 8, 0);
    } else if (a2 == -2) {
        Camera_ChangeSettingFlags(camera, 0x10, 0);
    } else {
        camera->unk156 = a2;
        camera->unk150 = a4;
        camera->unk162 = a5 + a6;
    }
    Camera_ResetActionFuncState(camera, camera->unk144);
    return -1;
}
