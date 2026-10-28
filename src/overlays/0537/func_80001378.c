// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80151DF4(s32, s32, u8 *);            /* extern */
M2C_UNK func_80B84584(u8 *, M2C_UNK, M2C_UNK);    /* extern */
extern M2C_UNK D_801E6EF0;

void func_80001378(u8 *arg0, s32 arg1) {
    s32 var_s1;

    var_s1 = 0x1254;
    if (M2C_FIELD(&D_801E6EF0, u8 *, 0x20) == 2) {
        var_s1 = 0x1257;
        if (M2C_FIELD(&D_801E6EF0, u8 *, 0xF47) & 1) {
            M2C_FIELD(arg0, s16 *, 0x304) = 3;
            func_80B84584(arg0, 4, 2);
        } else {
            var_s1 = 0x1255;
            if (M2C_FIELD(&D_801E6EF0, u8 *, 0xF46) & 0x40) {
                var_s1 = 0x1256;
                M2C_FIELD(arg0, s16 *, 0x304) = 1;
                func_80B84584(arg0, 2, 2);
            } else {
                M2C_FIELD(&D_801E6EF0, u8 *, 0xF46) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF46) | 0x40);
                M2C_FIELD(arg0, s16 *, 0x304) = 1;
                func_80B84584(arg0, 2, 2);
            }
        }
    } else {
        M2C_FIELD(arg0, s16 *, 0x304) = 3;
        func_80B84584(arg0, 5, 2);
    }
    func_80151DF4(arg1, var_s1 & 0xFFFF, arg0);
}
