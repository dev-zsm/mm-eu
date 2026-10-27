#include "types.h"
extern u32 SurfaceType_GetData();
u32 SurfaceType_GetFloorProperty2(void *a0, s32 a1, s32 a2) {
    u32 v = SurfaceType_GetData(a0, a1, a2, 0);
    return (v >> 26) & 0xF;
}
