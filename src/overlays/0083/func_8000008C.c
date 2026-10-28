// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800E0FAC(s32, s32);                    /* extern */
M2C_UNK func_8016AF54(s32, s32, M2C_UNK, M2C_UNK, s32, u8 *, s32); /* extern */

void func_8000008C(u8 *arg0, s32 arg1) {
    func_800E0FAC(arg1, arg0 + 0x144);
    func_8016AF54(arg1, M2C_FIELD(arg0, s16 *, 0x1C) + 3, 0xFF, 0, 0xBFF, arg0 + 0x24, (s32) M2C_FIELD(arg0, s16 *, 0xBE));
    M2C_FIELD((arg1 + (M2C_FIELD(arg0, s16 *, 0x1C) * 4)), s32 *, 0x1EF4) = 0;
}
