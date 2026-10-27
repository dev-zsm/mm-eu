// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

f32 func_800B6C90(void *arg0, void *arg1) {
    return M2C_FIELD(arg1, f32 *, 0x28) - M2C_FIELD(arg0, f32 *, 0x28);
}
