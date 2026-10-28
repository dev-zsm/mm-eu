// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_801529DC(s32);                             /* extern */
M2C_UNK func_80B16970(u8 *, s32);                 /* extern */
extern M2C_UNK D_80B16E10;

void func_80000B04(u8 *arg0, s32 arg1) {
    if (func_801529DC(arg1 + 0x4908) == 2) {
        M2C_FIELD(arg0, M2C_UNK **, 0x1F8) = &D_80B16E10;
    }
    func_80B16970(arg0, arg1);
}
