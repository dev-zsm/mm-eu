// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80A5DF80();                            /* extern */

void func_8000244C(u8 *arg0, M2C_UNK arg1) {
    if (!(M2C_FIELD(arg0, f32 *, 0x68) > 0.0f) && (M2C_FIELD(arg0, u8 *, 0x11C) == 0) && (M2C_FIELD(arg0, u16 *, 0x90) & 1)) {
        func_80A5DF80();
    }
}
