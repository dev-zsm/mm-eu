// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800E2318(s32, s32, u8 *);            /* extern */
M2C_UNK func_800E2500(s32, s32, u8 *);            /* extern */
M2C_UNK func_800E26E8(s32, s32, u8 *);            /* extern */
M2C_UNK func_80ADAB6C(u8 *, s32);                 /* extern */

void func_80001B3C(u8 *arg0, s32 arg1) {
    func_80ADAB6C(arg0, arg1);
    M2C_FIELD(arg0, M2C_UNK (**)(u8 *, s32), 0x1E8)(arg0, arg1);
    if (M2C_FIELD(arg0, u8 *, 0x284) & 1) {
        func_800E2318(arg1, arg1 + 0x18884, arg0 + 0x274);
    }
    if (M2C_FIELD(arg0, u8 *, 0x285) & 1) {
        func_800E2500(arg1, arg1 + 0x18884, arg0 + 0x274);
    }
    if (M2C_FIELD(arg0, u8 *, 0x286) & 1) {
        func_800E26E8(arg1, arg1 + 0x18884, arg0 + 0x274);
    }
}
