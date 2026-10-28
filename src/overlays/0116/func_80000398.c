// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800E09D8(s32, s32);                    /* extern */
M2C_UNK func_800E0FAC(s32, s32);                    /* extern */
M2C_UNK func_80138AB0(s32, s32);                    /* extern */

void func_80000398(s32 arg0, s32 arg1) {
    func_80138AB0(arg1, arg0 + 0x14C);
    func_800E0FAC(arg1, arg0 + 0x1EC);
    func_800E09D8(arg1, arg0 + 0x238);
}
