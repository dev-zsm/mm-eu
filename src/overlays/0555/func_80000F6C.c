#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFDD8(u8 *, s16, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80BA5AA8(u8 *);                      /* extern */

void func_80000F6C(u8 *arg0) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8 *, 0x1DC);
    if ((temp_v0 == 1) || (temp_v0 == 2) || (temp_v0 == 3) || (temp_v0 == 4)) {
        func_80BA5AA8(arg0);
    }
    func_800FFDD8(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x32), 3, 0x2AA8);
}
