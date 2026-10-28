// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800F1D6C(s8, u8 *);                  /* extern */

void func_800005D0(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, s8 *, 0x1AC) = (s8) (M2C_FIELD(arg0, s8 *, 0x1AC) - 1);
    if (M2C_FIELD(arg0, s8 *, 0x1AC) <= 0) {
        func_800F1D6C(M2C_FIELD(arg0, s8 *, 0x38), arg0);
        func_800B6490(arg0);
    }
}
