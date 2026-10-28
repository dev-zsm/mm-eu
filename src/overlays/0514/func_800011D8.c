// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8BDC(u8 *, s32);                 /* extern */
s32 func_800F1E2C();                                /* extern */
M2C_UNK func_8016B084(u8 *);                      /* extern */
M2C_UNK func_8019FF78(M2C_UNK);                     /* extern */

void func_800011D8(u8 *arg0, u8 *arg1) {
    u8 *temp_s0;

    temp_s0 = M2C_FIELD(arg1, u8 **, 0x1CCC);
    if (func_800F1E2C() == M2C_FIELD(arg0, s8 *, 0x38)) {
        if (M2C_FIELD(temp_s0, u16 *, 0x90) & 0x100) {
            func_800B8BDC(temp_s0, (M2C_FIELD(M2C_FIELD(temp_s0, u8 **, 0xA68), u16 *, 0x92) + 0x6805) & 0xFFFF);
            func_8016B084(arg1);
            func_800B8BDC(temp_s0, (M2C_FIELD(M2C_FIELD(temp_s0, u8 **, 0xA68), u16 *, 0x92) + 0x680C) & 0xFFFF);
            M2C_FIELD(arg1, s8 *, 0x18845) = 1;
            func_8019FF78(0x5801);
            M2C_FIELD(arg0, s32 *, 0x580) = 0;
        }
    } else {
        M2C_FIELD(arg0, s32 *, 0x580) = 0;
    }
}
