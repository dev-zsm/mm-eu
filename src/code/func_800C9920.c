// FLAGS: -O2 -g3 -mips2
#include "types.h"

u32 SurfaceType_GetData(s32, s32, s32, s32);

s32 SurfaceType_IsHorseBlocked(s32 a0, s32 a1, s32 a2) {
    return (SurfaceType_GetData(a0, a1, a2, 0) >> 0x1F) & 1;
}
