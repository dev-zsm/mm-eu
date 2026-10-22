// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 func_800B61B8(void *arg0, void *arg1) {
    if ((M2C_FIELD(arg0, u8 *, 0x1E8F) != 0) || (M2C_FIELD(arg0, s16 *, 0x1E90) != 0)) {
        M2C_FIELD(arg1, s8 *, 0xA) = 0;
        M2C_FIELD(arg1, s8 *, 0xB) = 0;
        return 0;
    }
    return 1;
}
