// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_809F39C8();                            /* extern */

void func_8000256C(u8 *arg0) {
    M2C_FIELD(arg0, f32 *, 0x3AC) = 0.0f;
    func_809F39C8();
}
