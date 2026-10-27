// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK BgCheck_RaycastFloorImpl(M2C_UNK, s32, M2C_UNK, M2C_UNK, M2C_UNK *, s32, s32, s32, f32, s32); /* extern */

void BgCheck_CameraRaycastFloor1(s32 arg0, M2C_UNK arg1, s32 arg2) {
    M2C_UNK sp34;

    BgCheck_RaycastFloorImpl(0, arg0, 1, arg1, &sp34, arg2, 0, 0x1C, 1.0f, 0);
}
