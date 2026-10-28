// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_8012458C(u8 *);                          /* extern */
s32 func_80124764(u8 *);                          /* extern */
M2C_UNK func_80136480(s32, u8 *);                 /* extern */
M2C_UNK func_8083181C(u8 *, s32);                 /* extern */
M2C_UNK func_8083C914(u8 *, s32);                 /* extern */
M2C_UNK func_8085893C(u8 *);                      /* extern */
M2C_UNK func_808589F4(s32, u8 *, M2C_UNK);        /* extern */

void func_8002B9C8(s32 arg0, u8 *arg1, M2C_UNK arg2) {
    u8 *temp_v0;

    func_8085893C(arg1);
    if (func_80124764(arg1) != 0) {
        func_808589F4(arg0, arg1, 0);
        return;
    }
    func_80136480(arg0, arg1 + 0x240);
    if ((func_8012458C(arg1) != 0) || (M2C_FIELD(arg1, s32 *, 0xA6C) & 0x800)) {
        func_8083181C(arg1, arg0);
        return;
    }
    temp_v0 = M2C_FIELD(arg1, u8 **, 0x388);
    if ((temp_v0 != NULL) && (M2C_FIELD(temp_v0, u16 *, 0x116) == 0xFFFF)) {
        func_8083C914(arg1, arg0);
    }
}
