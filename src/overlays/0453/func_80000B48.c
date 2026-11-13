#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0453.h"

M2C_UNK func_800EDCC4(u8 *, s32, s32);            /* extern */
s32 func_800EDFA0(s32, u16);                        /* extern */
s32 func_800EE03C(s32, u16);                        /* extern */
s32 func_80AE67A4(u8 *);                          /* extern */
M2C_UNK func_80AE6C18(u8 *);                      /* extern */
M2C_UNK func_80AE6DD0(u8 *);                      /* extern */
M2C_UNK func_80AE6E4C(u8 *);                      /* extern */
M2C_UNK func_80AE6F64(u8 *);                      /* extern */
extern M2C_UNK D_80AE742C;

void func_80000B48(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80AE742C;
    if (func_800EE03C(arg1, M2C_FIELD(arg0, u16 *, 0x24A)) != 0) {
        func_800EDCC4(arg0, arg1, func_800EDFA0(arg1, M2C_FIELD(arg0, u16 *, 0x24A)));
        if (M2C_FIELD(arg0, u16 *, 0x24C) != *((u16 **)(arg1 + 0x1F4C))[func_800EDFA0(arg1, M2C_FIELD(arg0, u16 *, 0x24A))]) {
            M2C_FIELD(arg0, u16 *, 0x24C) = (u16) *((u16 **)(arg1 + 0x1F4C))[func_800EDFA0(arg1, M2C_FIELD(arg0, u16 *, 0x24A))];
            func_80AE6C18(arg0);
        }
        func_80AE6DD0(arg0);
    }
    if (((M2C_FIELD(arg0, s16 *, 0x1C) & 0xF) < 4) && (func_80AE67A4(arg0) != 0)) {
        M2C_FIELD(arg0, M2C_UNK **, 0x13C) = NULL;
    }
    func_80AE6F64(arg0);
    func_80AE6E4C(arg0);
}
