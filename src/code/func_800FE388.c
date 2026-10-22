// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_801E6EF0;

s32 Environment_IsFinalHours(s32 arg0) {
    s32 var_v1;

    var_v1 = 0;
    if ((M2C_FIELD(&D_801E6EF0, s32 *, 0x18) == 3) && ((s32) M2C_FIELD(&D_801E6EF0, u16 *, 0xC) < 0x4000)) {
        var_v1 = 1;
    }
    return var_v1;
}
