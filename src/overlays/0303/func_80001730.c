// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern s32 D_80A07740;

void func_80001730(u8 *arg0) {
    D_80A07740 &= ~(1 << M2C_FIELD(arg0, u8 *, 0x1C0));
    M2C_FIELD(arg0, M2C_UNK (**)(), 0x15C)();
    M2C_FIELD(arg0, u8 *, 0x1C1) = (u8) (M2C_FIELD(arg0, u8 *, 0x1C1) & 0xFFFD);
}
