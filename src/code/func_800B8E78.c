// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80115F80();                            /* extern */

void Actor_DeactivateLens(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x1CA3) != 0) {
        M2C_FIELD(arg0, u8 *, 0x1CA3) = 0U;
        func_80115F80();
    }
}
