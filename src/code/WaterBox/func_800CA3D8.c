// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bgcheck.h"

u16 WaterBox_GetBgCamSetting(CollisionContext* colCtx, WaterBox* waterBox, s32 bgId) {
    s32 pad[2];
    u16 camSetting = CAM_SET_NONE;
    CollisionHeader* colHeader;
    BgCamInfo* bgCamList;
    s32 bgCamIndex;

    colHeader = BgCheck_GetCollisionHeader(colCtx, bgId);
    if (colHeader == NULL) {
        return camSetting;
    }

    bgCamIndex = WaterBox_GetBgCamIndex(colCtx, waterBox);
    bgCamList = colHeader->bgCamList;

    if (bgCamList == NULL) {
        return camSetting;
    }

    camSetting = bgCamList[bgCamIndex].setting;

    return camSetting;
}
