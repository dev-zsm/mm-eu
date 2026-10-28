// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FEE3C(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_80B293C0(u8 *);                      /* extern */
s32 func_80B299B0(u8 *, s32);                     /* extern */
M2C_UNK func_80B3010C(u8 *);                      /* extern */
M2C_UNK func_80B30240(u8 *);                      /* extern */

void func_80007AD4(u8 *arg0, s32 arg1) {
    s16 temp_v0;

    func_800FEE3C(arg0 + 0x70, 0x3F8CCCCD, 0x3F000000);
    if (func_80B299B0(arg0, arg1) != 0) {
        func_80B293C0(arg0);
    }
    func_80B3010C(arg0);
    if (M2C_FIELD(arg0, s8 *, 0x3BC) >= 0) {
        M2C_FIELD(arg0, s16 *, 0x2F0) = 0;
    }
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x2F0);
    if (temp_v0 > 0) {
        M2C_FIELD(arg0, s16 *, 0x2F0) = (s16) (temp_v0 - 1);
        return;
    }
    func_80B30240(arg0);
}
