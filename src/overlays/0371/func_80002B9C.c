// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80A72EEC();                            /* extern */

void func_80002B9C(u8 *arg0) {
    M2C_FIELD(arg0, f32 *, 0x3C0) = 0.0f;
    func_80A72EEC();
}
