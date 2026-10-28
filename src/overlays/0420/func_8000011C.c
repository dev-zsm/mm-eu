// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_801E6EF0;

void func_8000011C(u8 *arg0) {
    if ((M2C_FIELD(&D_801E6EF0, u8 *, 0xF4D) & 0x10) && !(M2C_FIELD(&D_801E6EF0, u8 *, 0xF4C) & 0x40)) {
        M2C_FIELD(arg0, u16 *, 0x3A8) = 0x88FU;
        return;
    }
    if (M2C_FIELD(arg0, u16 *, 0x3A8) == 0) {
        M2C_FIELD(arg0, u16 *, 0x3A8) = 0x84BU;
        return;
    }
    if (M2C_FIELD(&D_801E6EF0, u8 *, 0xF08) & 0x10) {
        M2C_FIELD(arg0, u16 *, 0x3A8) = 0x838U;
        return;
    }
    if (M2C_FIELD(&D_801E6EF0, u8 *, 0xF09) & 1) {
        M2C_FIELD(arg0, u16 *, 0x3A8) = 0x84DU;
        return;
    }
    M2C_FIELD(arg0, u16 *, 0x3A8) = 0x849U;
}
