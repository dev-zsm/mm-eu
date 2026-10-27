#include "types.h"

typedef struct {
    u8 pad0[0x1CCC];
    struct Actor *focus;
} CameraPlayState;
typedef struct Actor {
    u8 pad0[0x153];
    u8 form;
} Actor;
typedef struct {
    u8 pad0[0x8C];
    CameraPlayState *play;
    Actor *target;
    u8 pad94[0x164 - 0x94];
    s16 mode;
} Camera;
s32 Camera_ChangeSettingFlags(Camera *camera, s16 setting, s16 flags);
s32 Camera_RequestGiantsMaskSetting(Camera *camera) {
    Actor *player = ((0, camera->play))->focus;
    if (((camera->mode == 0) && (camera->target == ((0, camera->play))->focus)) && (player->form == 0x14)) {
        Camera_ChangeSettingFlags(camera, 0x4F, 2);
        return 1;
    }
    return 0;
}
