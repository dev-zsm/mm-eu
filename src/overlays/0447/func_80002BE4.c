#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B680C(s32);                         /* extern */
M2C_UNK func_800B763C(s32, s32, M2C_UNK, M2C_UNK, f32, s32); /* extern */
M2C_UNK func_800B8C4C(s32, M2C_UNK);                /* extern */
s32 func_80137C58(s32, M2C_UNK);                    /* extern */

void func_80002BE4(s32 arg0, s32 arg1) {
    s32 temp_a0;
    s32 sp24;

    func_800B680C(arg0);
    func_800B763C(arg1, arg0, 0x41F00000, 0x41400000, 0.0f, 4);
    temp_a0 = arg0 + 0x144;
    sp24 = temp_a0;
    if ((func_80137C58(temp_a0, 0x40400000) != 0) || (func_80137C58(temp_a0, 0x41000000) != 0)) {
        func_800B8C4C(arg0, 0x284A);
    }
}
