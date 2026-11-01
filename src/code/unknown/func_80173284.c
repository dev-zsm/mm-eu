// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK PreRender_ApplyFilters();                            /* extern */

void func_80173284(void *arg0) {
    if ((M2C_FIELD(arg0, s32 *, 0x18) != 0) && (M2C_FIELD(arg0, s32 *, 0x14) != 0)) {
        PreRender_ApplyFilters();
    }
}
