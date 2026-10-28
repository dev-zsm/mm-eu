// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80B78864();                            /* extern */

void func_80000898(u8 *arg0, s16 arg1) {
    func_80B78864();
    M2C_FIELD(arg0, s16 *, 0x31A) = arg1;
    M2C_FIELD(arg0, u16 *, 0x30A) = (u16) (M2C_FIELD(arg0, u16 *, 0x30A) | 4);
}
