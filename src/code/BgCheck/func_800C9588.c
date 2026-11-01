#include "types.h"
#include "generated/code_funcs.h"

typedef struct {
    u16 type;
    u16 count;
    void *data;
} BgCamInfo;

typedef struct {
    u8 pad0[0x20];
    BgCamInfo *bgCamList;
} CollisionHeader;


u16 BgCheck_GetBgCamCountImpl(void *colCtx, s32 camId, s32 bgId) {
    CollisionHeader *colHeader = BgCheck_GetCollisionHeader(colCtx, bgId);
    BgCamInfo *bgCamList;

    if (colHeader == NULL) {
        return 0;
    }
    bgCamList = colHeader->bgCamList;
    if (bgCamList == NULL) {
        return 0;
    }
    return bgCamList[camId].count;
}
