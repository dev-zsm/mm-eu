#include "types.h"
#include "m2c_compat.h"

s32 func_800B5B20(s32, s32, u8 *);                /* extern */
M2C_UNK func_80151DF4(s32, M2C_UNK, u8 *);        /* extern */
extern M2C_UNK D_801E6EF0;

void func_800028C4(u8 *arg0, s32 arg1) {
    M2C_UNK var_a1;
    u32 temp_v0;

    if (M2C_FIELD(&D_801E6EF0, u8 *, 0x20) == 2) {
        if (func_800B5B20(arg1, M2C_FIELD(arg0, s16 *, 0x18) & 0x7F, arg0) != 0) {
            var_a1 = 0x12C3;
            if (M2C_FIELD(&D_801E6EF0, u8 *, 0xF20) & 4) {
                var_a1 = 0x12C5;
            } else {
                M2C_FIELD(&D_801E6EF0, u8 *, 0xF20) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF20) | 4);
            }
        } else {
            var_a1 = 0x12C0;
            if (M2C_FIELD(&D_801E6EF0, u8 *, 0xF20) & 2) {
                var_a1 = 0x12C2;
            } else {
                M2C_FIELD(&D_801E6EF0, u8 *, 0xF20) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF20) | 2);
            }
        }
    } else if (func_800B5B20(arg1, M2C_FIELD(arg0, s16 *, 0x18) & 0x7F, arg0) != 0) {
        temp_v0 = M2C_FIELD(arg0, u16 *, 0x2F2);
        var_a1 = 0x12BE;
        if (temp_v0 & 0x10) {
            var_a1 = 0x12BF;
        } else {
            M2C_FIELD(arg0, u16 *, 0x2F2) = (u16) (temp_v0 | 0x10);
        }
    } else if (M2C_FIELD(&D_801E6EF0, u8 *, 0xF20) & 1) {
        var_a1 = 0x12BC;
    } else {
        M2C_FIELD(&D_801E6EF0, u8 *, 0xF20) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF20) | 1);
        var_a1 = 0x12BB;
        M2C_FIELD(arg0, u16 *, 0x2F2) = (u16) (M2C_FIELD(arg0, u16 *, 0x2F2) | 4);
    }
    func_80151DF4(arg1, var_a1, arg0);
}
