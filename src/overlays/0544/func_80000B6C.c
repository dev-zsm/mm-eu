// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80147B34(s32);                             /* extern */
M2C_UNK func_80147CC4(s32);                         /* extern */
s32 func_801529DC(s32);                             /* extern */
M2C_UNK func_80B940D8(u8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80B94180(u8 *);                      /* extern */
extern M2C_UNK D_80B94924;

void func_80000B6C(u8 *arg0, s32 arg1) {
    s32 temp_v0;

    func_80B94180(arg0);
    temp_v0 = func_801529DC(arg1 + 0x4908);
    if (temp_v0 != 2) {
        if ((temp_v0 == 5) && (func_80147B34(arg1) != 0)) {
            func_80147CC4(arg1);
            M2C_FIELD(arg0, M2C_UNK **, 0x29C) = &D_80B94924;
            func_80B940D8(arg0, 3, 2);
        }
    } else {
        M2C_FIELD(arg0, M2C_UNK **, 0x29C) = &D_80B94924;
        func_80B940D8(arg0, 3, 2);
    }
}
