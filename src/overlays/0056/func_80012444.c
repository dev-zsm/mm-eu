// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8BDC(s32, u16);                    /* extern */
M2C_UNK func_8082D5F8(s32, s32, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_80836550(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_80012444(s32 arg0, s32 arg1, u16 arg2) {
    func_80836550(arg0, 0x6C77, 7, 0x14);
    func_8082D5F8(arg0, arg1, 0xFF, 0x14, 0x96, 0);
    func_800B8BDC(arg1, arg2);
}
