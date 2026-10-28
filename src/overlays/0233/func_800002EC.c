// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B7DD4(s32, s32, M2C_UNK);           /* extern */
M2C_UNK func_800B7E9C(s32, s32, M2C_UNK);           /* extern */
M2C_UNK func_800EE0C0(s32, M2C_UNK);                /* extern */

void func_800002EC(s32 arg0, s32 arg1) {
    func_800B7E9C(arg0, arg1, 0);
    func_800B7DD4(arg0, arg1, 0);
    func_800EE0C0(arg1, 0x56);
}
