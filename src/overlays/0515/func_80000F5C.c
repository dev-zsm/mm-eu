// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s8 func_800CAD48(u8 *);                           /* extern */
s8 func_800CAD6C(u8 *);                           /* extern */

void func_80000F5C(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, s8 *, 0x180) = func_800CAD48(arg0);
    M2C_FIELD(arg0, s8 *, 0x181) = func_800CAD6C(arg0);
}
