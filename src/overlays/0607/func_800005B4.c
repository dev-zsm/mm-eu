// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80BD8B64();                            /* extern */
M2C_UNK func_80BD8C28();                            /* extern */

void func_800005B4(u8 *arg0) {
    if (M2C_FIELD(arg0, u16 *, 0x310) & 0x10) {
        func_80BD8B64();
        return;
    }
    func_80BD8C28();
}
