// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Camera_SetStateFlag(s32, M2C_UNK);                /* extern */
M2C_UNK Camera_UnsetStateFlag(s32, M2C_UNK);                /* extern */

s32 func_800DF258(s32 arg0) {
    Camera_SetStateFlag(arg0, 0xC);
    Camera_UnsetStateFlag(arg0, 0x1008);
    return 1;
}
