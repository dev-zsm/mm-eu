// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FEE3C(u8 *, s32, M2C_UNK, u8 *); /* extern */
M2C_UNK func_808968FC(u8 *, s32);                 /* extern */
M2C_UNK func_80896D68(u8 *);                      /* extern */
M2C_UNK func_80897C00(u8 *);                      /* extern */

void func_80001524(u8 *arg0, s32 arg1) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x2B0);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, s16 *, 0x2B0) = (s16) (temp_v0 - 1);
    }
    func_800FEE3C(arg0 + 0x28, M2C_FIELD(arg0, s32 *, 0x88), 0x41000000, arg0);
    if (M2C_FIELD(arg0, s16 *, 0x2B0) == 0) {
        func_808968FC(arg0, arg1);
        if (M2C_FIELD(arg0, u8 *, 0xB7) == 0) {
            func_80897C00(arg0);
            return;
        }
        func_80896D68(arg0);
    }
}
