#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0344.h"

M2C_UNK func_8013B284(u8 *, M2C_UNK, M2C_UNK, u8 *); /* extern */

s32 func_80000118(u8 *arg0, u8 *arg1) {
    s32 var_v1;
    u16 temp_v0;
    u32 temp_v0_2;
    s32 sp1C;

    var_v1 = 0;
    if (M2C_FIELD(arg1, u8 *, 0x1F2C) != 0) {
        temp_v0 = M2C_FIELD(arg0, u16 *, 0x37C);
        if (!(temp_v0 & 0x20)) {
            M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~1);
            M2C_FIELD(arg0, u8 *, 0x1DC) = 0xFF;
            M2C_FIELD(arg0, u16 *, 0x37C) = (u16) (temp_v0 | 0x20);
        }
        func_8013B284(arg0 + 0x37C, 0, 7, arg0);
        var_v1 = 1;
    } else {
        temp_v0_2 = M2C_FIELD(arg0, u16 *, 0x37C);
        if (temp_v0_2 & 0x20) {
            M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 1);
            M2C_FIELD(arg0, u8 *, 0x1DC) = 0xFF;
            M2C_FIELD(arg0, u16 *, 0x37C) = (u16) (temp_v0_2 & 0xFFDF);
            sp1C = 0;
            func_8013B284(arg0 + 0x37C, 3, 7, arg0);
            var_v1 = 0;
        }
    }
    return var_v1;
}
