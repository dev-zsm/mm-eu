// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s16 func_800FF860(u8 *, u8 *);                  /* extern */
u8 *func_8013DD10(u8 *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 func_80B9669C(u8 *, u8 *);                  /* extern */

s32 func_80000444(u8 *arg0, u8 *arg1) {
    u8 *temp_v0;
    u8 *var_s0;

    temp_v0 = func_8013DD10(arg1, 0, 7, 0xB9);
    if (temp_v0 != NULL) {
        M2C_FIELD(arg0, s16 *, 0x4B0) = func_800FF860(arg0 + 0x24, temp_v0 + 0x24);
        if (func_80B9669C(arg0, temp_v0) != 0) {
            return 1;
        }
    }
    var_s0 = M2C_FIELD(arg1, u8 **, 0x1CD8);
    if (var_s0 != NULL) {
loop_4:
        if ((M2C_FIELD(var_s0, s16 *, 0) == 9) && (func_80B9669C(arg0, var_s0) != 0)) {
            M2C_FIELD(arg0, s16 *, 0x4B0) = func_800FF860(arg0 + 0x24, var_s0 + 0x24);
            if (M2C_FIELD(arg0, u16 *, 0x230) & 0x200) {
                return 0;
            }
            if (M2C_FIELD(var_s0, u8 *, 0x1F9) == 0) {
                return 2;
            }
            return 3;
        }
        var_s0 = M2C_FIELD(var_s0, u8 **, 0x12C);
        if (var_s0 == NULL) {
            goto block_12;
        }
        goto loop_4;
    }
block_12:
    M2C_FIELD(arg0, u16 *, 0x230) = (u16) (M2C_FIELD(arg0, u16 *, 0x230) & 0xFDFF);
    return 0;
}
