// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80958C30(s32, M2C_UNK *);              /* extern */
M2C_UNK func_80959280(s32);                         /* extern */
M2C_UNK func_809596F8(s32, s32);                    /* extern */
s32 func_80959764(s32, s32);                        /* extern */
extern M2C_UNK D_8095A6D8;

void func_800016D0(s32 arg0, s32 arg1) {
    if (func_80959764(arg0, arg1) != 0) {
        func_80959280(arg0);
        func_80958C30(arg0, &D_8095A6D8);
        return;
    }
    func_809596F8(arg0, arg1);
}
