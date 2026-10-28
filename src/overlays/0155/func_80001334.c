// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8091F978();                            /* extern */
M2C_UNK func_8091F9B4(u8 *);                      /* extern */
M2C_UNK func_80920824(u8 *);                      /* extern */

void func_80001334(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, s8 *, 0x164) = (s8) (M2C_FIELD(arg0, s8 *, 0x164) - 1);
    if (M2C_FIELD(arg0, s8 *, 0x164) <= 0) {
        func_8091F978();
        func_8091F9B4(arg0);
        func_80920824(arg0);
    }
}
