// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6730(s32);                         /* extern */
M2C_UNK func_8098FBA0(s32);                         /* extern */
M2C_UNK func_8098FBD4(s32, M2C_UNK);                /* extern */

void func_800000B8(s32 arg0) {
    func_8098FBA0(arg0);
    func_8098FBD4(arg0 + 0x64, 0x3D4CCCCD);
    func_800B6730(arg0);
}
