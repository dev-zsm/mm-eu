// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 SurfaceType_IsFloorConveyor(s32, s32, u8, void *);            /* extern */
s32 SurfaceType_GetConveyorSpeed(s32, s32, u8, void *);            /* extern */
extern s32 D_801ED310;

s32 Distortion_GetUnderwaterCurrentSpeed(void *arg0) {
    if (SurfaceType_IsFloorConveyor(D_801ED310 + 0x830, M2C_FIELD(arg0, s32 *, 0x80), M2C_FIELD(arg0, u8 *, 0x85), arg0) == 0) {
        return SurfaceType_GetConveyorSpeed(D_801ED310 + 0x830, M2C_FIELD(arg0, s32 *, 0x80), M2C_FIELD(arg0, u8 *, 0x85), arg0);
    }
    return 0;
}
