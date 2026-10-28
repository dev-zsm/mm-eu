// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80B98980();                            /* extern */
M2C_UNK func_80B98A54();                            /* extern */

void func_8000273C(u8 *arg0) {
    if (M2C_FIELD(arg0, u16 *, 0x230) & 1) {
        func_80B98A54();
        return;
    }
    func_80B98980();
}
