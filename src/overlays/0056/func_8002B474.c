// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8082D270(s32, s32);                    /* extern */
M2C_UNK func_8082DFD0(s32, s32, M2C_UNK);           /* extern */

void func_8002B474(s32 arg0, s32 arg1) {
    func_8082D270(arg0, arg1);
    func_8082DFD0(arg0, arg1, 0x9C);
}
