// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80913958();                            /* extern */

void func_80000BA8(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, s16 *, 0x222) = (s16) (M2C_FIELD(arg0, s16 *, 0x222) + 1);
    if (M2C_FIELD(arg0, s16 *, 0x222) >= 3) {
        func_80913958();
    }
}
