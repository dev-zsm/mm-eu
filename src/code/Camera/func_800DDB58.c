// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK ZeldaArena_Free();                            /* extern */

void Camera_Destroy(struct Camera *camera) {
    if (camera != 0) {
        ZeldaArena_Free();
    }
}
