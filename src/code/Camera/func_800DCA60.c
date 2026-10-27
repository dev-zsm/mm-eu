// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Camera_Noop();                            /* extern */

void Camera_Special1(void) {
    Camera_Noop();
}
