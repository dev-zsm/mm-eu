// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK ZeldaArena_Free();                            /* extern */

void Camera_Destroy(s32 arg0) {
    if (arg0 != 0) {
        ZeldaArena_Free();
    }
}
