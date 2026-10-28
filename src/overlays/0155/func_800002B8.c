// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800F1D6C(s8, u8 *);                  /* extern */

void func_800002B8(u8 *arg0) {
    if (M2C_FIELD(arg0, s8 *, 0x172) != 0) {
        func_800F1D6C(M2C_FIELD(arg0, s8 *, 0x38), arg0);
        M2C_FIELD(arg0, s8 *, 0x172) = 0;
    }
}
