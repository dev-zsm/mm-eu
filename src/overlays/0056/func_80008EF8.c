#include "types.h"
#include "m2c_compat.h"

s32 func_801238D0();                                /* extern */
s32 func_801238E4(s32, s32);                        /* extern */
M2C_UNK func_80835F38(s32, s32);                    /* extern */
M2C_UNK func_80835FDC(s32, s32);                    /* extern */
M2C_UNK func_8085AA78(s32, s32);                    /* extern */

void func_80008EF8(s32 arg0, s32 arg1) {
    if (func_801238D0(arg0) != 0) {
        func_80835F38(arg0, arg1);
        return;
    }
    if (func_801238E4(arg0, arg1) != 0) {
        func_80835FDC(arg0, arg1);
        return;
    }
    func_8085AA78(arg0, arg1);
}
