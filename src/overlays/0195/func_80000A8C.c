// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8095954C();                            /* extern */
M2C_UNK func_8095961C();                            /* extern */

void func_80000A8C(u8 *arg0) {
    if (M2C_FIELD(arg0, s16 *, 0x52A) != 0) {
        func_8095961C();
        return;
    }
    func_8095954C();
}
