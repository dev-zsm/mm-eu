#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8013B284(u8 *, M2C_UNK, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_80B22004;
extern M2C_UNK func_80B21E4C;

s32 func_80000624(u8 *arg0, u8 *arg1) {
    s32 var_v1;
    s32 sp1C;
    u16 temp_v0;

    var_v1 = 0;
    if (M2C_FIELD(arg1, u8 *, 0x1F2C) != 0) {
        temp_v0 = M2C_FIELD(arg0, u16 *, 0x322);
        if (!(temp_v0 & 0x200)) {
            M2C_FIELD(arg0, u16 *, 0x322) = (u16) (temp_v0 | 0x210);
            M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~1);
            M2C_FIELD(arg0, u8 *, 0x324) = 0xFF;
        }
        func_8013B284(arg0 + 0x322, 0, 7, arg0);
        var_v1 = 1;
        M2C_FIELD(arg0, M2C_UNK **, 0x188) = &func_80B21E4C;
    } else if (M2C_FIELD(arg0, u16 *, 0x322) & 0x200) {
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 1);
        sp1C = 0;
        func_8013B284(arg0 + 0x322, 3, 7, arg0);
        var_v1 = 0;
        M2C_FIELD(arg0, u16 *, 0x322) = (u16) (M2C_FIELD(arg0, u16 *, 0x322) & 0xFDEF);
        M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80B22004;
    }
    return var_v1;
}
