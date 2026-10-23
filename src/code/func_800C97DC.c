#include "types.h"
extern s32 SurfaceType_GetWallType();
extern s32 D_801B5150[];
s32 SurfaceType_GetWallFlags(void) {
    return D_801B5150[SurfaceType_GetWallType()];
}
