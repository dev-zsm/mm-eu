// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801A3D04(M2C_UNK, u8 *);             /* extern */
M2C_UNK func_8086AF84(u8 *);                      /* extern */

void func_80003458(u8 *arg0, M2C_UNK arg1) {
    if (M2C_FIELD(arg0, s16 *, 0x1C) == 2) {
        func_801A3D04(0x38, arg0);
        func_8086AF84(arg0);
    }
}
