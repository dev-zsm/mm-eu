// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FEC70(u8 *, s16, M2C_UNK, u8 *); /* extern */

void func_8000010C(u8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x32);
    if (temp_v0 & 0x3FFF) {
        func_800FEC70(arg0 + 0x32, (s16) ((s16) (temp_v0 + 0x2000) & 0xC000), 0x640, arg0);
        M2C_FIELD(arg0, s16 *, 0xBE) = (s16) M2C_FIELD(arg0, s16 *, 0x32);
    }
}
