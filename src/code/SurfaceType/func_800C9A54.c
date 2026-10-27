// FLAGS: -O2 -g3 -mips2
#include "types.h"
extern u32 SurfaceType_GetData();
s32 SurfaceType_GetEcho(s32 a0, s32 a1, s32 a2) {
    return (SurfaceType_GetData(a0, a1, a2, 1) >> 11) & 0x3F;
}
