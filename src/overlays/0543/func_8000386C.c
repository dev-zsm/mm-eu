// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800B680C(u8 *);                      /* extern */
M2C_UNK func_800FFBF8(u8 *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80B90930(u8 *, M2C_UNK);             /* extern */

void func_8000386C(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;
    s16 var_v1;

    func_80B90930(arg0, 0);
    if (M2C_FIELD(arg0, s32 *, 0x1F4) == -0x63) {
        func_800B6490(arg0);
    }
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x3F6);
    M2C_FIELD(arg0, s16 *, 0x3F2) = (s16) M2C_FIELD(arg0, s16 *, 0x2DE);
    if (temp_v0 == 0) {
        var_v1 = 0;
    } else {
        M2C_FIELD(arg0, s16 *, 0x3F6) = (s16) (temp_v0 - 1);
        var_v1 = M2C_FIELD(arg0, s16 *, 0x3F6);
    }
    if (var_v1 == 0) {
        func_800FFBF8(arg0 + 0x70, 0x40C00000, 0x3E4CCCCD, 0x3F000000);
    }
    func_800B680C(arg0);
}
