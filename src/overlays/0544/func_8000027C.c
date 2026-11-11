#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80151DF4(s32, u16, u8 *);            /* extern */
M2C_UNK func_80B940D8(u8 *, M2C_UNK, M2C_UNK, u16); /* extern */
extern M2C_UNK D_801E6EF0;

void func_8000027C(u8 *arg0, s32 arg1) {
    u16 var_a3;

    if (M2C_FIELD(&D_801E6EF0, u8 *, 0x20) != 2) {
        var_a3 = 0x1227;
        if (M2C_FIELD(&D_801E6EF0, u8 *, 0xF18) & 8) {
            var_a3 = 0x1229;
        } else {
            M2C_FIELD(&D_801E6EF0, u8 *, 0xF18) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF18) | 8);
        }
    } else if (M2C_FIELD(arg0, u16 *, 0x256) & 1) {
        var_a3 = 0x1225;
    } else {
        var_a3 = 0x1219;
        if (M2C_FIELD(&D_801E6EF0, u8 *, 0xF18) & 0x10) {
            var_a3 = 0x1226;
        } else {
            M2C_FIELD(&D_801E6EF0, u8 *, 0xF18) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF18) | 0x10);
        }
        M2C_FIELD(arg0, u16 *, 0x256) = (u16) (M2C_FIELD(arg0, u16 *, 0x256) | 1);
    }
    func_80B940D8(arg0, 0, 2, var_a3);
    func_80151DF4(arg1, var_a3, arg0);
}
