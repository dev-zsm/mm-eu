// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6FD0(s32, u8 *, M2C_UNK);        /* extern */
M2C_UNK func_800F1D6C(s8);                          /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
u8 *func_8013DD10(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 func_8016A844(s32, s16);                        /* extern */
M2C_UNK func_8016A87C(s32, M2C_UNK, s32, s32);      /* extern */
M2C_UNK func_80B47224(u8 *);                      /* extern */

void func_80000AA4(u8 *arg0, s32 arg1) {
    s32 temp_v0;
    u8 *temp_v0_2;

    func_80137070(arg0 + 0x144);
    M2C_FIELD(arg0, s16 *, 0x206) = (s16) (M2C_FIELD(arg0, s16 *, 0x206) - 1);
    if (M2C_FIELD(arg0, s16 *, 0x206) == 0) {
        temp_v0 = func_8016A844(arg1, M2C_FIELD(arg0, s16 *, 0x20E));
        func_8016A87C(arg1, 0, temp_v0 + 0x50, temp_v0 + 0x5C);
        M2C_FIELD(arg0, s16 *, 0x20E) = 0;
        if (M2C_FIELD(arg0, s16 *, 0x1C) == 1) {
            temp_v0_2 = func_8013DD10(arg1, 0, 4, 0x1CA);
            if (temp_v0_2 != NULL) {
                M2C_FIELD(temp_v0_2, s16 *, 0x1C) = (s16) M2C_FIELD(arg0, s8 *, 0x38);
            } else {
                func_800F1D6C(M2C_FIELD(arg0, s8 *, 0x38));
            }
        } else {
            func_800F1D6C(M2C_FIELD(arg0, s8 *, 0x38));
        }
        func_800B6FD0(arg1, arg0, 6);
        func_80B47224(arg0);
    }
}
