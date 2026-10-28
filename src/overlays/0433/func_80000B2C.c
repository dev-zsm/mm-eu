// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8013CD14(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_80ACAE60(u8 *);                      /* extern */
M2C_UNK func_80ACB0D8(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80ACB324(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80ACB620(u8 *, M2C_UNK);             /* extern */

void func_80000B2C(u8 *arg0, M2C_UNK arg1) {
    func_80ACB620(arg0, arg1);
    M2C_FIELD(arg0, M2C_UNK (**)(u8 *, M2C_UNK), 0x144)(arg0, arg1);
    func_80ACB324(arg0, arg1);
    func_80ACAE60(arg0);
    func_80ACB0D8(arg0, arg1);
    M2C_FIELD(arg0, s32 *, 0x2E0) = 0;
    func_8013CD14(arg0, arg1, 0x42F00000, 0x42200000, 0, M2C_FIELD(arg0, u16 *, 0x1D8) & 7);
}
