// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_808AF8E8();                            /* extern */
M2C_UNK func_808AFC5C(u8 *);                      /* extern */

void func_800007D8(u8 *arg0) {
    func_808AF8E8();
    if (M2C_FIELD(arg0, s16 *, 0x32) == M2C_FIELD(arg0, s16 *, 0x23C)) {
        func_808AFC5C(arg0);
    }
}
