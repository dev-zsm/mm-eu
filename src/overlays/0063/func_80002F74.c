// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80869788();                            /* extern */
M2C_UNK func_8086BCC8(u8 *);                      /* extern */
M2C_UNK func_8086BEE8(u8 *);                      /* extern */

void func_80002F74(u8 *arg0) {
    s16 temp_v0;

    M2C_FIELD(arg0, s16 *, 0x2BC) = (s16) (M2C_FIELD(arg0, s16 *, 0x2BC) - 1);
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x2BC);
    if (temp_v0 == 0) {
        func_80869788();
        func_8086BEE8(arg0);
        return;
    }
    if (temp_v0 == 0x4E) {
        func_80869788();
        M2C_FIELD(arg0, s8 *, 0x11C) = 0;
        func_8086BCC8(arg0);
    }
}
