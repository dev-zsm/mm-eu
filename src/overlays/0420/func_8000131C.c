// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80136ED0(s32, s32, M2C_UNK *, M2C_UNK *, s32, s32, s32); /* extern */
extern M2C_UNK D_6000A44;
extern M2C_UNK D_600FEF0;
extern M2C_UNK D_80ABA418;

void func_8000131C(u8 *arg0, s32 arg1) {
    func_80136ED0(arg1, arg0 + 0x150, &D_600FEF0, &D_6000A44, 0, 0, 0);
    M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80ABA418;
}
