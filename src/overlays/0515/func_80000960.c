// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800C625C(s32, s32, s32, u8 *);       /* extern */

void func_80000960(u8 *arg0, s32 arg1) {
    s32 pad;
    s32 sp1C;
    s32 temp_v0;
    u8 *temp_v0_2;
    u8 *temp_v0_3;
    u8 *temp_v0_4;
    u8 *temp_v0_5;

    temp_v0 = ((s16) M2C_FIELD(arg0, s16 *, 0x1C) >> 8) & 3;
    sp1C = temp_v0;
    func_800C625C(arg1, arg1 + 0x880, M2C_FIELD(arg0, s32 *, 0x144), arg0);
    if (temp_v0 == 0) {
        temp_v0_2 = M2C_FIELD(arg0, u8 **, 0x15C);
        if (temp_v0_2 != NULL) {
            M2C_FIELD(temp_v0_2, s32 *, 0x164) = 0;
        }
        temp_v0_3 = M2C_FIELD(arg0, u8 **, 0x160);
        if (temp_v0_3 != NULL) {
            M2C_FIELD(temp_v0_3, s32 *, 0x164) = 0;
        }
    } else if (temp_v0 == 1) {
        temp_v0_4 = M2C_FIELD(arg0, u8 **, 0x164);
        if (temp_v0_4 != NULL) {
            M2C_FIELD(temp_v0_4, s32 *, 0x15C) = 0;
        }
    } else if (temp_v0 == 2) {
        temp_v0_5 = M2C_FIELD(arg0, u8 **, 0x164);
        if (temp_v0_5 != NULL) {
            M2C_FIELD(temp_v0_5, s32 *, 0x160) = 0;
        }
    }
}
