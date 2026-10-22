// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 SurfaceType_GetData(s32, s32, s32, s32);

s32 SurfaceType_IsWallDamage(s32 a0, s32 a1, s32 a2) {
    s32 var_v1;

    if (SurfaceType_GetData(a0, a1, a2, 1) & 0x08000000) {
        var_v1 = 1;
    } else {
        var_v1 = 0;
    }
    return var_v1;
}
