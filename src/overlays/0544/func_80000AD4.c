#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80151DF4(s32, u16, s32);               /* extern */
M2C_UNK func_80B940D8(s32, M2C_UNK, M2C_UNK, u16);  /* extern */
extern M2C_UNK D_801E6EF0;

void func_80000AD4(s32 arg0, s32 arg1) {
    u16 var_a3;

    if (M2C_FIELD(&D_801E6EF0, u8 *, 0x20) == 2) {
        if (M2C_FIELD(&D_801E6EF0, u8 *, 0xF47) & 1) {
            var_a3 = 0x1253;
        } else {
            var_a3 = 0x1251;
            if (M2C_FIELD(&D_801E6EF0, u8 *, 0xF46) & 0x20) {
                var_a3 = 0x1252;
            } else {
                M2C_FIELD(&D_801E6EF0, u8 *, 0xF46) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF46) | 0x20);
            }
        }
    } else {
        var_a3 = 0x1250;
    }
    func_80B940D8(arg0, 0, 2, var_a3);
    func_80151DF4(arg1, var_a3, arg0);
}
