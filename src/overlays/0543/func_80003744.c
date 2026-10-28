// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B680C(u8 *);                      /* extern */
M2C_UNK func_800FFBF8(u8 *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80B90830(u8 *, M2C_UNK, M2C_UNK);    /* extern */

void func_80003744(u8 *arg0, M2C_UNK arg1) {
    func_80B90830(arg0, 1, 2);
    if (M2C_FIELD(arg0, s32 *, 0x1F8) == -0x63) {
        M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    } else {
        M2C_FIELD(arg0, s16 *, 0x3F2) = (s16) M2C_FIELD(arg0, s16 *, 0x2DE);
        func_800FFBF8(arg0 + 0x70, 0x40C00000, 0x3E4CCCCD, 0x3F000000);
    }
    func_800B680C(arg0);
}
