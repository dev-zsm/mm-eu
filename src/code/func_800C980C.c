// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 SurfaceType_GetWallFlags();                                /* extern */

s32 SurfaceType_CheckWallFlag0(void) {
    s32 var_v1;

    if (SurfaceType_GetWallFlags() & 1) {
        var_v1 = 1;
    } else {
        var_v1 = 0;
    }
    return var_v1;
}
