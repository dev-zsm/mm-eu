// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8013698C(s32, s32, s32, M2C_UNK);      /* extern */
M2C_UNK func_80830DDC(s32, s32, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_8084F300;

void func_80010278(s32 arg0, s32 arg1, s32 arg2) {
    func_80830DDC(arg2, arg0, &D_8084F300, 0);
    func_8013698C(arg2, arg0 + 0x240, arg1, 0x3FAAAAAB);
}
