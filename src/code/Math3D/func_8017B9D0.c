// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Math_Vec3f_DistXYZ();                            /* extern */

void func_8017B9D0(void) {
    Math_Vec3f_DistXYZ();
}
