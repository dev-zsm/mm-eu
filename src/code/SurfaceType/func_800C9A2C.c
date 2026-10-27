#include "types.h"
extern u32 SurfaceType_GetData();
u32 SurfaceType_GetLightSettingIndex(void *a0, s32 a1, s32 a2) {
    u32 v = SurfaceType_GetData(a0, a1, a2, 1);
    return (v >> 6) & 0x1F;
}
