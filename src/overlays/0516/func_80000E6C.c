// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800F1944(s16);                         /* extern */
s32 func_800F1984(s16);                             /* extern */
M2C_UNK func_800F1A08(s16, u8 *);                 /* extern */
s32 func_80B68A24(u8 *, M2C_UNK);                 /* extern */
M2C_UNK func_80B68AB4(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80B68B3C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80B698BC(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80B69C10(u8 *, M2C_UNK);             /* extern */

void func_80000E6C(u8 *arg0, M2C_UNK arg1) {
    s32 pad;
    s32 sp20;

    if (func_800F1984(M2C_FIELD(arg0, s16 *, 0x1A4)) != 0) {
        sp20 = func_80B68A24(arg0, arg1);
        func_800F1A08(M2C_FIELD(arg0, s16 *, 0x1A4), arg0);
        M2C_FIELD(arg0, s8 *, 0x1A3) = 1;
        if (sp20 != 0) {
            func_80B68AB4(arg0, arg1);
            func_80B69C10(arg0, arg1);
            return;
        }
        func_80B68B3C(arg0, arg1);
        func_80B698BC(arg0, arg1);
        return;
    }
    func_800F1944(M2C_FIELD(arg0, s16 *, 0x1A4));
}
