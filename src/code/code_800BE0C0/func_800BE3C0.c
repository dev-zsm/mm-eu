// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 func_800BE3C0(void *arg0) {
    u8 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8 *, 0x1F1);
    if ((temp_v0 == 5) || (temp_v0 == 6) || (temp_v0 == 7) || (temp_v0 == 8) || (temp_v0 == 0xC)) {
        return 1;
    }
    return 0;
}
