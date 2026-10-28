// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B8364(u8 *, s32, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80151DF4(s32, M2C_UNK, u8 *);        /* extern */
M2C_UNK func_80BF8DD0(u8 *);                      /* extern */

void func_80000CE0(u8 *arg0, s32 arg1) {
    if (func_800B8254(arg0, arg1) != 0) {
        func_80151DF4(arg1, 0x10A4, arg0);
        M2C_FIELD(arg0, s16 *, 0x300) = 0x10A4;
        func_80BF8DD0(arg0);
        return;
    }
    func_800B8364(arg0, arg1, 0x43480000, -1);
}
