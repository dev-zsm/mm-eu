// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800F1944(s16);                         /* extern */
s32 func_800F1984(s16);                             /* extern */
M2C_UNK func_800F1A08(s16, u8 *);                 /* extern */
M2C_UNK func_800F1D6C(M2C_UNK);                     /* extern */
s32 func_800F1E2C();                                /* extern */

void func_80000F18(u8 *arg0, u8 *arg1) {
    u8 *sp24;

    sp24 = M2C_FIELD(arg1, u8 **, 0x1CCC);
    if (func_800F1984(M2C_FIELD(arg0, s16 *, 0x3DA)) != 0) {
        func_800F1A08(M2C_FIELD(arg0, s16 *, 0x3DA), arg0);
        M2C_FIELD(sp24, s32 *, 0xA6C) = (s32) (M2C_FIELD(sp24, s32 *, 0xA6C) | 0x20);
        M2C_FIELD(arg0, s16 *, 0x3B2) = 6;
        return;
    }
    if (func_800F1E2C() == 0x7C) {
        func_800F1D6C(0x7C);
    }
    func_800F1944(M2C_FIELD(arg0, s16 *, 0x3DA));
}
