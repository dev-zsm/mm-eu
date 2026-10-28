// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_808E6398();                            /* extern */
M2C_UNK func_808E9FBC(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_808EAEFC();                            /* extern */

void func_80005ABC(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x2BE) = (s16) (M2C_FIELD(arg0, s16 *, 0x2BE) - 1);
    if (M2C_FIELD(arg0, s16 *, 0x2BE) == 0) {
        if (M2C_FIELD(arg0, u8 *, 0x2B5) == 0xA) {
            func_808E6398();
            func_808E9FBC(arg0, 0);
            return;
        }
        M2C_FIELD(arg0, u8 *, 0x63D) = (u8) (M2C_FIELD(arg0, u8 *, 0x63D) & 0xFFFE);
        func_808EAEFC();
    }
}
