#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8082D1C8(s32, u8 *, M2C_UNK *);      /* extern */
s32 func_8082EBD4(u8 *, M2C_UNK);                 /* extern */
M2C_UNK func_80830E10(s32, u8 *, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_400DCA8;
extern M2C_UNK D_80853150;

s32 func_8002DE08(s32 arg0, u8 *arg1, M2C_UNK arg2) {
    s32 var_v1;
    s32 sp24;
    s32 temp_v0;

    temp_v0 = func_8082EBD4(arg1, arg2);
    var_v1 = temp_v0;
    if ((temp_v0 >= 0x3A) && (temp_v0 < 0x52) && (temp_v0 == (M2C_FIELD(arg1, u8 *, 0x153) + 0x39))) {
        var_v1 = 0;
    }
    if ((var_v1 <= 0) || (var_v1 >= 0x53)) {
        return -1;
    }
    M2C_FIELD(arg1, s8 *, 0x14A) = 0;
    M2C_FIELD(arg1, s32 *, 0x748) = 0;
    sp24 = var_v1;
    func_80830E10(arg0, arg1, &D_80853150, 0);
    M2C_FIELD(arg1, s8 *, 0xA86) = 0x7C;
    M2C_FIELD(arg1, s8 *, 0x14A) = (s8) var_v1;
    func_8082D1C8(arg0, arg1, &D_400DCA8);
    M2C_FIELD(arg1, s32 *, 0xA6C) = (s32) (M2C_FIELD(arg1, s32 *, 0xA6C) | 0x20000040);
    M2C_FIELD(arg1, s8 *, 0xB2A) = 0;
    M2C_FIELD(arg1, s8 *, 0xA87) = (s8) sp24;
    return sp24;
}
