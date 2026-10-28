// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_8017A844(f32);                             /* extern */
M2C_UNK func_80181BD8(f32, M2C_UNK);                /* extern */
M2C_UNK func_80182CA0(f32, s32);                    /* extern */
extern f32 D_809ED02C;

void func_80000390(s32 arg0, f32 arg1) {
    func_80181BD8(func_8017A844(D_809ED02C), 0);
    func_80182CA0(arg1, arg0);
}
