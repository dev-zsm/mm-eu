// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80BE07BC(s32, u8 *, M2C_UNK);        /* extern */
M2C_UNK func_80BE0AF4(u8 *, s32);                 /* extern */
s32 func_80BE0C10(u8 *, s32);                     /* extern */
extern M2C_UNK D_80BE1198;

void func_80000D1C(u8 *arg0, s32 arg1) {
    u8 *temp_a1;

    func_80BE0AF4(arg0, arg1);
    if (func_80BE0C10(arg0, arg1) == 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x430) = &D_80BE1198;
        func_80BE07BC(arg1, arg0, 8);
        temp_a1 = M2C_FIELD(arg0, u8 **, 0x40C);
        if (temp_a1 != NULL) {
            func_80BE07BC(arg1, temp_a1, 8);
        }
    }
}
