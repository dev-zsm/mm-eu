// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80134AE8(s32);                             /* extern */
M2C_UNK func_801367B4(s32, s32, s32, M2C_UNK, f32, f32, s32, f32); /* extern */
M2C_UNK func_8082D16C(s32);                         /* extern */
M2C_UNK func_8082DE34(s32);                         /* extern */

void func_8002B27C(s32 arg0, s32 arg1, s32 arg2) {
    func_8082DE34(arg1);
    func_801367B4(arg0, arg1 + 0x240, arg2, 0x3F2AAAAB, 0.0f, (f32) func_80134AE8(arg2), 2, -8.0f);
    func_8082D16C(arg1);
}
