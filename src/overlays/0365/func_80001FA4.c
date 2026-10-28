// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BBB30(s32, u8 *, u8 *, s32, s32, f32, s32, s32, s32); /* extern */
M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80A5E4E4(u8 *);                      /* extern */

void func_80001FA4(u8 *arg0, s32 arg1) {
    u8 temp_v0;
    u8 temp_v0_2;

    M2C_FIELD(arg0, s16 *, 0xBE) = (s16) (M2C_FIELD(arg0, s16 *, 0xBE) - 0x1770);
    func_800BBB30(arg1, arg0, arg0 + 0x24, M2C_FIELD(arg0, s32 *, 0xCC), 1, 4.0f, 0x12C, 5, 1);
    func_800FFCBC(arg0 + 0x32, M2C_FIELD(arg0, s16 *, 0x92), 1, 0xFA0, 0x14);
    if ((M2C_FIELD(arg0, s16 *, 0x28E) == 0) || (temp_v0 = M2C_FIELD(arg0, u8 *, 0xF50), ((temp_v0 & 2) != 0)) || (temp_v0 & 4) || (temp_v0_2 = M2C_FIELD(arg0, u8 *, 0xFD0), ((temp_v0_2 & 2) != 0)) || (temp_v0_2 & 4)) {
        M2C_FIELD(arg0, u8 *, 0xF50) = (u8) (M2C_FIELD(arg0, u8 *, 0xF50) & 0xFFF9);
        M2C_FIELD(arg0, u8 *, 0xFD0) = (u8) (M2C_FIELD(arg0, u8 *, 0xFD0) & 0xFFF9);
        func_80A5E4E4(arg0);
    }
}
