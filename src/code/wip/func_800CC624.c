#include "types.h"

typedef struct {
    u8 pad0[0x8C];
    u8 *unk8C;
    s32 unk90;
} CamLike;

extern void Actor_GetWorldPosShapeRot(s32 *, s32);
extern s32 BgCheck_GetWaterSurface(u8 *, u8 *, s32, s32, f32 *, s32 *, s32 *);
extern s32 Camera_IsSwimming(CamLike *);
extern s32 WaterBox_GetBgCamSetting(u8 *, s32, s32);

s32 Camera_GetWaterBoxBgCamSetting(CamLike *a0, f32 *a1) {
    s32 pad2[2];
    struct { s32 a; f32 b; s32 c; } sp3C;
    s32 sp38;
    s32 pad;
    s32 sp30;
    register s32 ret;

    Actor_GetWorldPosShapeRot(&sp3C.a, a0->unk90);
    *a1 = sp3C.b;
    if (BgCheck_GetWaterSurface(a0->unk8C, a0->unk8C + 0x830, sp3C.a, sp3C.c, a1, &sp38, &sp30) == 0) {
        *a1 = sp3C.b;
        return -1;
    }
    if (Camera_IsSwimming(a0) == 0) {
        return -1;
    }
    pad = WaterBox_GetBgCamSetting(a0->unk8C + 0x830, sp38, sp30);
    if (pad == 0) {
        ret = -2;
    } else {
        ret = pad;
    }
    return ret;
}
