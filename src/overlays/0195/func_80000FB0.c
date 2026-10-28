// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_809592D0(u8 *);                      /* extern */

s32 func_80000FB0(u8 *arg0, M2C_UNK arg1) {
    s32 var_v1;
    u8 temp_v0_3;
    u8 *temp_v0;
    u8 *temp_v0_2;

    var_v1 = 0;
    temp_v0 = arg0 + 0x2F4;
    if (M2C_FIELD(arg0, u8 *, 0x305) & 2) {
        var_v1 = 1;
        M2C_FIELD(temp_v0, u8 *, 0x11) = (u8) (M2C_FIELD(temp_v0, u8 *, 0x11) & 0xFFFD);
    }
    temp_v0_2 = arg0 + 0x340;
    if (M2C_FIELD(arg0, u8 *, 0x351) & 2) {
        var_v1 = 1;
        M2C_FIELD(temp_v0_2, u8 *, 0x11) = (u8) (M2C_FIELD(temp_v0_2, u8 *, 0x11) & 0xFFFD);
    }
    if (var_v1 == 0) {
        return 0;
    }
    temp_v0_3 = M2C_FIELD(arg0, u8 *, 0x5C4);
    M2C_FIELD(arg0, s16 *, 0x526) = 8;
    if ((s32) temp_v0_3 <= 0) {
        M2C_FIELD(arg0, u8 *, 0x5C4) = (u8) (temp_v0_3 + 1);
    }
    if (M2C_FIELD(arg0, s16 *, 0x52A) == 0) {
        func_800B8C4C(arg0, 0x389E);
        func_800B8C4C(arg0, 0x6867);
    }
    func_809592D0(arg0);
    M2C_FIELD(arg0, u16 *, 0x5C2) = (u16) (M2C_FIELD(arg0, u16 *, 0x5C2) | 1);
    return 0;
}
