// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_8013E684(u8 *, s16, M2C_UNK, M2C_UNK);   /* extern */

void func_80001790(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK (**)(), 0x15C)();
    if ((M2C_FIELD(arg0, u16 *, 0x172) & 8) && (func_8013E684(arg0, M2C_FIELD(arg0, s16 *, 0x1D2), -1, 0) != 0)) {
        M2C_FIELD(arg0, u16 *, 0x172) = (u16) (M2C_FIELD(arg0, u16 *, 0x172) & 0xFFF7);
    }
}
