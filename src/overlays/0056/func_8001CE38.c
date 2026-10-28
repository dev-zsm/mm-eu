// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80136480(s32, s32);                        /* extern */
s32 func_80832708(s32, s32, M2C_UNK *, M2C_UNK);    /* extern */
M2C_UNK func_80835FDC(s32, s32);                    /* extern */
extern M2C_UNK D_8085C6F4;

void func_8001CE38(s32 arg0, s32 arg1) {
    s32 sp1C;

    sp1C = func_80136480(arg1, arg0 + 0x240);
    if ((func_80832708(arg1, arg0, &D_8085C6F4, 1) == 0) && (sp1C != 0)) {
        func_80835FDC(arg0, arg1);
    }
}
