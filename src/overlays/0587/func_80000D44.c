// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFDD8(u8 *, s16, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80BC5E5C(u8 *);                      /* extern */

void func_80000D44(u8 *arg0) {
    u8 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8 *, 0x1D8);
    if ((temp_v0 == 1) || (temp_v0 == 2)) {
        func_80BC5E5C(arg0);
    }
    func_800FFDD8(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x32), 3, 0x2AA8);
}
