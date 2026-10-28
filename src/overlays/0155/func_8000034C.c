// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800CAD00(u8 *);                          /* extern */

void func_8000034C(u8 *arg0, s32 arg1) {
    if (func_800CAD00(arg0) != 0) {
        M2C_FIELD(arg0, s8 *, 0x170) = (s8) arg1;
    }
}
