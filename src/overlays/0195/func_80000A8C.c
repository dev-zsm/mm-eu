// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0195.h"

M2C_UNK func_8095954C();                            /* extern */
M2C_UNK func_8095961C();                            /* extern */

void func_80000A8C(Actor *thisx) {
    if (M2C_FIELD(thisx, s16 *, 0x52A) != 0) {
        func_8095961C();
        return;
    }
    func_8095954C();
}
