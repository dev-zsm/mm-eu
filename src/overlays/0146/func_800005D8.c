#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0146.h"

M2C_UNK func_8013B284(u8 *, M2C_UNK, M2C_UNK);    /* extern */
s16 func_80911564(u8 *);                          /* extern */

s32 func_800005D8(u8 *arg0, u8 *arg1) {
    s32 var_v1;

    var_v1 = 0;
    if (M2C_FIELD(arg1, u8 *, 0x1F2C) != 0) {
        if (!(M2C_FIELD(arg0, u16 *, 0x2C6) & 0x80)) {
            M2C_FIELD(arg0, s16 *, 0x2C8) = func_80911564(arg0);
            M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~1);
            func_8013B284(arg0 + 0x2C6, 0, 7);
            M2C_FIELD(arg0, s8 *, 0x1D8) = 0xFF;
            M2C_FIELD(arg0, u16 *, 0x2C6) = (u16) (M2C_FIELD(arg0, u16 *, 0x2C6) | 0x80);
            M2C_FIELD(arg0, u8 *, 0x1D8) = 0xFF;
        }
        var_v1 = 1;
    } else if (M2C_FIELD(arg0, u16 *, 0x2C6) & 0x80) {
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 1);
        func_8013B284(arg0 + 0x2C6, 3, 7);
        var_v1 = 0;
        M2C_FIELD(arg0, u16 *, 0x2C6) = (u16) (M2C_FIELD(arg0, u16 *, 0x2C6) & 0xFF7F);
    }
    return var_v1;
}
