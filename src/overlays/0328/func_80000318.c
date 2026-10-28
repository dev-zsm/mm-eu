// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800F1944(s8);                          /* extern */
M2C_UNK func_800F1D6C(s8);                          /* extern */
s32 func_80147B34(u8 *);                          /* extern */
s32 func_801529DC(s32);                             /* extern */

s32 func_80000318(u8 *arg0, u8 *arg1) {
    if ((func_801529DC(arg1 + 0x4908) == 5) && (func_80147B34(arg1) != 0)) {
        if (M2C_FIELD(M2C_FIELD(arg0, u8 **, 0xD78), u16 *, 2) == 0x145F) {
            func_800F1D6C(M2C_FIELD(arg0, s8 *, 0xD8D));
            M2C_FIELD(arg0, s8 *, 0xD8D) = 0x7C;
            func_800F1944(M2C_FIELD(arg0, s8 *, 0xD8D));
            M2C_FIELD(arg0, s32 *, 0x730) = (s32) M2C_FIELD(arg1, s32 *, 0x1CCC);
        }
        return 1;
    }
    return 0;
}
