#include "types.h"
#include "generated/code_funcs.h"

typedef struct { u8 pad0[0x1C]; void *unk1C; void *unk20; } ColHeader;


s32 BgCheck_GetBgCamFuncData(void *colCtx, void *poly, s32 bgId) {
    ColHeader *hdr = BgCheck_GetCollisionHeader(colCtx, bgId);
    void *a;
    void *b;

    if (hdr == 0) {
        return 0;
    }
    a = hdr->unk20;
    if (a == 0) {
        return 0;
    }
    b = hdr->unk1C;
    if (b == 0) {
        return 0;
    }
    return BgCheck_GetBgCamFuncDataImpl(colCtx, SurfaceType_GetBgCamIndex(colCtx, poly, bgId), bgId);
}
