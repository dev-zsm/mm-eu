// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800F1944(s8, u8 *);                  /* extern */
M2C_UNK func_8091D25C(u8 *);                      /* extern */

void func_80001A38(u8 *arg0, M2C_UNK arg1) {
    if (M2C_FIELD(arg0, u8 *, 0x200) != 0) {
        func_800F1944(M2C_FIELD(arg0, s8 *, 0x38), arg0);
        func_8091D25C(arg0);
    }
}
