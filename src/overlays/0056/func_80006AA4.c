// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8082D63C(s32, M2C_UNK);                /* extern */
M2C_UNK func_80833B70(s32, s32);                    /* extern */

void func_80006AA4(s32 arg0, s32 arg1) {
    func_8082D63C(arg1, 0x6808);
    func_80833B70(arg0, arg1);
}
