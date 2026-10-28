// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80A424F4;

void func_800025F4(u8 *arg0) {
    s32 var_v0;
    u8 *var_v1;

    M2C_FIELD(arg0, s32 *, 0x194) = 0;
    var_v0 = 1;
    var_v1 = arg0 + 4;
    do {
        var_v0 += 4;
        M2C_FIELD(var_v1, s32 *, 0x198) = 0;
        M2C_FIELD(var_v1, s32 *, 0x19C) = 0;
        M2C_FIELD(var_v1, s32 *, 0x1A0) = 0;
        var_v1 += 0x10;
        M2C_FIELD(var_v1, s32 *, 0x184) = 0;
    } while (var_v0 != 9);
    M2C_FIELD(arg0, M2C_UNK **, 0x190) = &D_80A424F4;
}
