// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_809834D0(u8 *, M2C_UNK, u8 *);     /* extern */
extern M2C_UNK D_80983990;
extern M2C_UNK D_80983B64;

void func_80000448(u8 *arg0, M2C_UNK arg1) {
    s32 var_v0;

    var_v0 = (s32) (M2C_FIELD(arg0, s16 *, 0x1C) & 0x7E00) >> 9;
    if (var_v0 != 0x3F) {
        func_809834D0(arg0 + 0x148, 6, arg0);
        var_v0 = (s32) (M2C_FIELD(arg0, s16 *, 0x1C) & 0x7E00) >> 9;
    }
    if (var_v0 != 0x3F) {
        M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80983990;
        return;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80983B64;
}
