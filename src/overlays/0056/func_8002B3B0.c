// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8082D16C(s32);                         /* extern */
M2C_UNK func_8082DC58(s32, s32, s32);               /* extern */
M2C_UNK func_8082DE34(s32);                         /* extern */

void func_8002B3B0(s32 arg0, s32 arg1, s32 arg2) {
    func_8082DE34(arg1);
    func_8082DC58(arg0, arg1, arg2);
    func_8082D16C(arg1);
}
