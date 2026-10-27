#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
} Hdr;

extern Hdr *BgCheck_GetCollisionHeader(s32, s32);
extern s32 SurfaceType_GetBgCamIndex(s32, s32, s32);
extern s32 BgCheck_GetBgCamSettingImpl(s32, s32, s32);

s32 BgCheck_GetBgCamSetting(s32 a0, s32 a1, s32 a2) {
    Hdr *h = BgCheck_GetCollisionHeader(a0, a2);
    s32 v1;

    if (h == 0) {
        return 0;
    }
    v1 = h->unk20;
    if (v1 == 0) {
        return 0;
    }
    v1 = h->unk1C;
    if (v1 == 0) {
        return 0;
    }
    return BgCheck_GetBgCamSettingImpl(a0, SurfaceType_GetBgCamIndex(a0, a1, a2), a2);
}
