// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8082D2D8();                            /* extern */
M2C_UNK func_8082DD80(u8 *);                      /* extern */

void func_80000D04(u8 *arg0) {
    u8 temp_v0;

    if (M2C_FIELD(arg0, u8 *, 0x275) != 0) {
        func_8082D2D8();
        M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x260), s16 *, 0) = (s16) M2C_FIELD(arg0, s16 *, 0x27E);
        M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x260), s16 *, 4) = (s16) M2C_FIELD(arg0, s16 *, 0x282);
        temp_v0 = M2C_FIELD(arg0, u8 *, 0x275);
        if (temp_v0 & 8) {
            if (temp_v0 & 2) {
                M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x260), s16 *, 2) = (s16) M2C_FIELD(arg0, s16 *, 0x27A);
            }
        } else {
            M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x260), s16 *, 2) = (s16) M2C_FIELD(arg0, s16 *, 0x280);
        }
        func_8082DD80(arg0);
        M2C_FIELD(arg0, u8 *, 0x275) = 0U;
    }
}
