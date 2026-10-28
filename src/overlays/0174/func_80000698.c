// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8093F63C();                            /* extern */

void func_80000698(u8 *arg0) {
    func_8093F63C();
    M2C_FIELD(arg0, s8 *, 0x40B) = 0;
    M2C_FIELD(arg0, s16 *, 0x3DE) = 0;
    M2C_FIELD(arg0, u16 *, 0x3E8) = (u16) (M2C_FIELD(arg0, u16 *, 0x3E8) | 0x10);
    M2C_FIELD(arg0, s8 *, 0x40C) = 4;
    M2C_FIELD(arg0, s8 *, 0x408) = 0;
    M2C_FIELD(arg0, s8 *, 0x40A) = 0;
    M2C_FIELD(arg0, s8 *, 0x409) = 4;
}
