// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_809136B0();                            /* extern */

void func_8000090C(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, s16 *, 0x222) = (s16) (M2C_FIELD(arg0, s16 *, 0x222) + 1);
    if (M2C_FIELD(arg0, s16 *, 0x222) >= 3) {
        func_809136B0();
        M2C_FIELD(arg0, s16 *, 0x220) = 0xC8;
    }
}
