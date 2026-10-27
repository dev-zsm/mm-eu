// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Math_Vec3f_Copy();                            /* extern */

void FireObj_SetPosition(void) {
    Math_Vec3f_Copy();
}
