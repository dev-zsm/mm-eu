#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(s32, M2C_UNK);                /* extern */
s32 func_80137C58(s32, M2C_UNK);                    /* extern */
M2C_UNK func_80869814(s32, s32);                    /* extern */

void func_80000920(s32 arg0, s32 arg1) {
    s32 temp_a0;

    temp_a0 = arg0 + 0x144;
    if (func_80137C58(temp_a0, 0x3F800000) != 0) {
        func_800B8C4C(arg0, 0x395B);
        return;
    }
    if (func_80137C58(temp_a0, 0x41300000) != 0) {
        func_80869814(arg0, arg1);
        func_800B8C4C(arg0, 0x2902);
    }
}
