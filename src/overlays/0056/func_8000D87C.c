// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80836038();                            /* extern */
M2C_UNK func_80839E6C();                            /* extern */

void func_8000D87C(u8 *arg0) {
    if (M2C_FIELD(arg0, f32 *, 0xAD0) != 0.0f) {
        func_80839E6C();
        return;
    }
    func_80836038();
}
