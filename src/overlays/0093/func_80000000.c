// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800E0F5C(s32, s32, u8 *);            /* extern */
M2C_UNK func_800E10CC(s32, s32, u8 *, M2C_UNK *); /* extern */
extern M2C_UNK D_808B4A40;

void func_80000000(u8 *arg0, s32 arg1) {
    s32 sp1C;
    s32 temp_a1;

    temp_a1 = arg0 + 0x144;
    sp1C = temp_a1;
    func_800E0F5C(arg1, temp_a1, arg0);
    func_800E10CC(arg1, temp_a1, arg0, &D_808B4A40);
    if (M2C_FIELD(arg0, s16 *, 0x1C) != 0) {
        M2C_FIELD(arg0, s32 *, 0x15C) = 0x40000;
    }
}
