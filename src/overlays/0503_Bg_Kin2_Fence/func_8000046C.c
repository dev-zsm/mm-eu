// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0503.h"

M2C_UNK func_80B539F4();                            /* extern */

void BgKin2Fence_WaitBeforeOpen(u8 *arg0, M2C_UNK arg1) {
    s8 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s8 *, 0x282);
    if (temp_v0 > 0) {
        M2C_FIELD(arg0, s8 *, 0x282) = (s8) (temp_v0 - 1);
        return;
    }
    func_80B539F4();
}
