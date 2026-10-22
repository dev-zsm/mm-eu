// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 SurfaceType_GetFloorType(s32, s32, M2C_UNK);               /* extern */

s32 func_800B8E30(s32 arg0, M2C_UNK arg1, s32 arg2, M2C_UNK arg3) {
    if (SurfaceType_GetFloorType(arg0 + 0x830, arg2, arg3) == 8) {
        return 1;
    }
    return 0;
}
