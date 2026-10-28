// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80B63D54;

void func_800005AC(u8 *arg0) {
    M2C_FIELD(arg0, u8 *, 0x17C) = (u8) (M2C_FIELD(arg0, u8 *, 0x17C) & 0xFFF8);
    M2C_FIELD(arg0, s8 *, 0x17D) = 0x28;
    M2C_FIELD(arg0, M2C_UNK **, 0x160) = &D_80B63D54;
}
