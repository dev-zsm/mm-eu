// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern u32 SurfaceType_GetData();

u32 SurfaceType_GetWallType(s32 a0, s32 a1, s32 a2) {
    return (((u32)SurfaceType_GetData(a0, a1, a2, 0)) >> 21) & 0x1F;
}
