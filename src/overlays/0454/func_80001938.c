// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80AE7E28();                            /* extern */
extern M2C_UNK D_80AE9378;

void func_80001938(u8 *arg0) {
    func_80AE7E28();
    M2C_FIELD(arg0, s32 *, 0x13C) = 0;
    M2C_FIELD(arg0, s8 *, 0x208) = 0x32;
    M2C_FIELD(arg0, s32 *, 0x80) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x1A4) = &D_80AE9378;
}
