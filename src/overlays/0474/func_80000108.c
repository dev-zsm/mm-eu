// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80B0D88C();                            /* extern */
extern s32 D_80B10010;
extern s32 D_80B10014;

s32 func_80000108(u8 *arg0) {
    u8 *temp_v0;
    u8 *temp_v0_2;

    if (M2C_FIELD(arg0, u8 *, 0x2C8) == 0) {
        if ((D_80B10014 != 0) && ((D_80B10010 != 1) || (temp_v0 = M2C_FIELD(arg0, u8 **, 0x350), (temp_v0 == NULL)) || (M2C_FIELD(temp_v0, s32 *, 0x138) == 0)) && (M2C_FIELD(arg0, s32 *, 0x2B0) == 0)) {
            M2C_FIELD(arg0, s16 *, 0x2B4) = 0;
            M2C_FIELD(arg0, s32 *, 0x2C4) = 0;
            M2C_FIELD(arg0, s16 *, 0x2B6) = (s16) M2C_FIELD(arg0, s16 *, 0x2B4);
            func_80B0D88C();
            return 1;
        }
        goto block_10;
    }
    temp_v0_2 = M2C_FIELD(arg0, u8 **, 0x350);
    if ((temp_v0_2 == NULL) || (M2C_FIELD(temp_v0_2, s32 *, 0x138) == 0)) {
        M2C_FIELD(arg0, s16 *, 0x2B4) = 0;
        M2C_FIELD(arg0, s32 *, 0x2C4) = 0;
        M2C_FIELD(arg0, s16 *, 0x2B6) = (s16) M2C_FIELD(arg0, s16 *, 0x2B4);
        func_80B0D88C();
        return 1;
    }
block_10:
    return 0;
}
