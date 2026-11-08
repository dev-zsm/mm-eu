// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0174.h"

M2C_UNK func_8093F63C();                            /* extern */

void func_80000698(Actor *thisx) {
    func_8093F63C();
    M2C_FIELD(thisx, s8 *, 0x40B) = 0;
    M2C_FIELD(thisx, s16 *, 0x3DE) = 0;
    M2C_FIELD(thisx, u16 *, 0x3E8) = (u16) (M2C_FIELD(thisx, u16 *, 0x3E8) | 0x10);
    M2C_FIELD(thisx, s8 *, 0x40C) = 4;
    M2C_FIELD(thisx, s8 *, 0x408) = 0;
    M2C_FIELD(thisx, s8 *, 0x40A) = 0;
    M2C_FIELD(thisx, s8 *, 0x409) = 4;
}
