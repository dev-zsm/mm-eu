// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B8254(s32, s32);                        /* extern */
M2C_UNK func_800B8398(s32, s32, M2C_UNK);           /* extern */
M2C_UNK func_80151DF4(s32, M2C_UNK, s32);           /* extern */
s32 func_801529DC(s32);                             /* extern */

void func_80000540(s32 arg0, s32 arg1) {
    if (func_801529DC(arg1 + 0x4908) == 0) {
        if (func_800B8254(arg0, arg1) != 0) {
            func_80151DF4(arg1, 0x24F, arg0);
            return;
        }
        func_800B8398(arg0, arg1, 0x42A00000);
    }
}
