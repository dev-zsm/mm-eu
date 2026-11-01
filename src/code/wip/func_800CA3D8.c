#include "types.h"

typedef struct {
    u16 setting;
    u16 unk2;
    u32 unk4;
} BgCamInfo;

typedef struct {
    u8 pad0[0x20];
    BgCamInfo *bgCamList;
} CollisionHeader;

extern CollisionHeader *BgCheck_GetCollisionHeader(void *colCtx, s32 bgId);
extern s32 WaterBox_GetBgCamIndex(void *colCtx, void *waterBox);

u16 WaterBox_GetBgCamSetting(void *colCtx, void *waterBox, s32 bgId) {
    CollisionHeader *colHeader = BgCheck_GetCollisionHeader(colCtx, bgId);
    s32 bgCamIndex;
    s32 pad[2];

    if (colHeader == NULL) {
        return 0;
    }
    bgCamIndex = WaterBox_GetBgCamIndex(colCtx, waterBox);
    if (colHeader->bgCamList == NULL) {
        return 0;
    }
    return colHeader->bgCamList[bgCamIndex].setting;
}
