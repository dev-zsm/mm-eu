// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800F1D6C(s16);                         /* extern */

void func_80000870(u8 *arg0, u8 *arg1) {
    if (M2C_FIELD(arg0, s8 *, 0x38) != -1) {
        func_800F1D6C(M2C_FIELD(arg1, s16 *, 0x1879C));
    }
}
