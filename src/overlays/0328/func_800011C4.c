// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FEC70(u8 *, s16, M2C_UNK, u8 *); /* extern */

s32 func_800011C4(u8 *arg0, M2C_UNK arg1) {
    func_800FEC70(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x16), 0x320, arg0);
    M2C_FIELD(arg0, s16 *, 0xAD4) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    return 0;
}
