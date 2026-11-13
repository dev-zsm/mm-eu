#include "types.h"
#include "m2c_compat.h"

extern s32 D_801EAB9C;
extern M2C_UNK D_80B3C628;

s32 func_80001AA4(u8 *arg0, u8 *arg1) {
    s32 var_v1;
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg1, u16 *, 0x1F36);
    var_v1 = 0;
    if ((M2C_FIELD(arg1, u8 *, 0x1F2C) != 0) && (M2C_FIELD(arg1, s16 *, 0xA4) == 0x61) && (D_801EAB9C == 0) && ((temp_v0 == 0) || (temp_v0 == 1))) {
        if (M2C_FIELD(arg0, s32 *, 0x3B0) == 0) {
            M2C_FIELD(arg0, s16 *, 0x38A) = 0;
            M2C_FIELD(arg0, s16 *, 0x38C) = 0;
            M2C_FIELD(arg0, u16 *, 0x360) = (u16) (M2C_FIELD(arg0, u16 *, 0x360) | 0x300);
            M2C_FIELD(arg0, s16 *, 0x38E) = 8;
            M2C_FIELD(arg0, u8 *, 0x364) = 0xFF;
            M2C_FIELD(arg0, s32 *, 0x3B0) = 1;
            M2C_FIELD(arg0, s32 *, 0x3B4) = 0;
        }
        var_v1 = 1;
    } else if (M2C_FIELD(arg0, s32 *, 0x3B0) != 0) {
        M2C_FIELD(arg0, s32 *, 0x3B0) = 0;
        M2C_FIELD(arg0, s32 *, 0x3B4) = 0;
        M2C_FIELD(arg0, s32 *, 0x3C0) = 1;
        M2C_FIELD(arg0, s8 *, 3) = (s8) M2C_FIELD(arg1, s8 *, 0x186E0);
        M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80B3C628;
    }
    return var_v1;
}
