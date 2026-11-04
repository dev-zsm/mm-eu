#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[0x8C];
    /* 0x8C */ s32 play;
} Camera;

extern s32 BgCheck_GetBgCamSettingImpl(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_8016ADEC(s32 arg0, s32 arg1);

s16 Camera_GetBgCamOrActorCsCamSetting(Camera *camera, s32 camId) {
    if (camId & 0x1000) {
        return BgCheck_GetBgCamSettingImpl(camera->play + 0x830, camId & ~0x1000, 0x32, camId);
    }
    return func_8016ADEC(camera->play, camId);
}
