// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 SurfaceType_GetData(s32, s32, s32, s32);

u8 SurfaceType_GetBgCamIndex(s32 a0, s32 a1, s32 a2) {
    return SurfaceType_GetData(a0, a1, a2, 0) & 0xFF;
}
