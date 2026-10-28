// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8018122C();                            /* extern */
M2C_UNK func_8018125C();                            /* extern */
M2C_UNK func_801820CC(s16, s16, s16, M2C_UNK);      /* extern */
M2C_UNK func_80182B28(s32, s32);                    /* extern */

void func_8000120C(s32 arg0, s32 arg1, s16 arg2, s16 arg3, s16 arg4) {
    func_8018122C();
    func_801820CC(arg2, arg3, arg4, 0);
    func_80182B28(arg0, arg1);
    func_8018125C();
}
