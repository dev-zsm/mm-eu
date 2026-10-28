// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B701C(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_801A40B0(M2C_UNK, M2C_UNK, s32);       /* extern */

s32 func_800012E4(u8 *arg0, M2C_UNK arg1) {
    func_800B701C(arg1, 0, 0x44, arg1);
    func_801A40B0(0x54, 4, (M2C_FIELD(arg0, u8 *, 0x2B3) ^ 0xF) & 0xFF);
    M2C_FIELD(arg0, s8 *, 0x2B1) = 4;
    return 0;
}
