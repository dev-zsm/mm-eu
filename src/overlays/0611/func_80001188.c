// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80147B34(s32);                             /* extern */
M2C_UNK func_80147CC4(s32);                         /* extern */
s32 func_801529DC(s32);                             /* extern */
M2C_UNK func_80BE0AF4(u8 *, s32);                 /* extern */
extern M2C_UNK D_80BE1414;

void func_80001188(u8 *arg0, s32 arg1) {
    func_80BE0AF4(arg0, arg1);
    if ((func_801529DC(arg1 + 0x4908) == 5) && (func_80147B34(arg1) != 0)) {
        func_80147CC4(arg1);
        M2C_FIELD(arg0, M2C_UNK **, 0x430) = &D_80BE1414;
    }
}
