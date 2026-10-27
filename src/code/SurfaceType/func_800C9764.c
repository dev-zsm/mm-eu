// FLAGS: -O2 -g3 -mips2
#include "types.h"

u32 SurfaceType_GetData(void *, void *, void *, s32);

s32 SurfaceType_GetFloorType(void *a0, void *a1, void *a2) {
    return (SurfaceType_GetData(a0, a1, a2, 0) >> 13) & 0x1F;
}
