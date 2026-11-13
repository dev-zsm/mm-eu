#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8D94(u8 *, M2C_UNK);             /* extern */
s32 func_800EDFA0(s32, u16);                        /* extern */
s32 func_800EE03C(s32, u16);                        /* extern */
M2C_UNK func_80AE6C18(u8 *);                      /* extern */
M2C_UNK func_80AE6DD0(u8 *);                      /* extern */
M2C_UNK func_80AE6E4C(u8 *);                      /* extern */
M2C_UNK func_80AE6F64(u8 *);                      /* extern */
M2C_UNK func_80AE7084(u8 *, s32, s32);            /* extern */

void func_80000A40(u8 *arg0, s32 arg1) {
    if (func_800EE03C(arg1, M2C_FIELD(arg0, u16 *, 0x24A)) != 0) {
        func_80AE7084(arg0, arg1, func_800EDFA0(arg1, M2C_FIELD(arg0, u16 *, 0x24A)));
        if (M2C_FIELD(arg0, u16 *, 0x24C) != *((u16 **)(arg1 + 0x1F4C))[func_800EDFA0(arg1, M2C_FIELD(arg0, u16 *, 0x24A))]) {
            M2C_FIELD(arg0, u16 *, 0x24C) = (u16) *((u16 **)(arg1 + 0x1F4C))[func_800EDFA0(arg1, M2C_FIELD(arg0, u16 *, 0x24A))];
            func_80AE6C18(arg0);
        }
        func_80AE6DD0(arg0);
    }
    func_80AE6F64(arg0);
    if (M2C_FIELD(arg0, u16 *, 0x24C) == 5) {
        func_800B8D94(arg0, 0x1063);
    }
    func_80AE6E4C(arg0);
}
