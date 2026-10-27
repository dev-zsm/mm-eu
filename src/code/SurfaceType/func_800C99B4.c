#include "types.h"

extern u8 D_801B51F0[];
extern s32 SurfaceType_GetMaterial(void *colCtx, void *poly, s32 bgId);

s32 SurfaceType_HasMaterialProperty(void *colCtx, void *poly, s32 bgId, s32 mask) {
    s32 material = SurfaceType_GetMaterial(colCtx, poly, bgId);

    if (material < 0 || material >= 0xF) {
        return 0;
    }
    return D_801B51F0[material] & mask;
}
