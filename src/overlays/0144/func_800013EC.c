#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800F1D6C(s8);                          /* extern */
M2C_UNK func_800FEE3C(s32, f32, M2C_UNK);       /* extern */
s32 func_80137070(u8 *);                          /* extern */
s32 func_8016A844(s32, s16);                        /* extern */
M2C_UNK func_8016A87C(s32, s16, u8 *, s32);       /* extern */
M2C_UNK func_8090E91C(u8 *, s32);                 /* extern */
M2C_UNK func_8090E978(u8 *);                      /* extern */

void func_800013EC(u8 *arg0, s32 arg1) {
    s16 temp_a1;

    func_800FEE3C(arg0 + 0x70, 0, 0x3F800000);
    temp_a1 = M2C_FIELD(arg0, s16 *, 0x2FA);
    if (temp_a1 != 0) {
        func_8016A87C(arg1, M2C_FIELD(arg0, s16 *, 0x2FA), arg0 + 0x3C, func_8016A844(arg1, temp_a1) + 0x5C);
    }
    if (func_80137070(arg0 + 0x144) != 0) {
        if (M2C_FIELD(arg0, s16 *, 0x2FA) != 0) {
            func_800F1D6C(M2C_FIELD(arg0, s8 *, 0x38));
            M2C_FIELD(arg0, s16 *, 0x2FA) = 0;
            func_8090E978(arg0);
            return;
        }
        func_8090E91C(arg0, arg1);
        return;
    }
    M2C_FIELD(arg0, u8 *, 0x11C) = 0xC;
    M2C_FIELD(arg0, s16 *, 0x2FC) = 0xC;
}
