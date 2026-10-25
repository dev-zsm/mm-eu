#include "types.h"

extern u16 D_801B51D0[];
extern s32 SurfaceType_GetMaterial(void *a0, void *a1, s32 a2);

u16 SurfaceType_GetSfxOffset(void *a0, void *a1, s32 a2) {
    s32 idx = SurfaceType_GetMaterial(a0, a1, a2);

    if (idx < 0 || idx >= 0xF) {
        return 0;
    }
    return D_801B51D0[idx];
}
