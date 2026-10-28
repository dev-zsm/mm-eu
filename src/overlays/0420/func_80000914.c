// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80AB97A8();                            /* extern */

void func_80000914(u8 *arg0) {
    if (M2C_FIELD(arg0, f32 *, 0x28) < 5.0f) {
        func_80AB97A8();
        if (M2C_FIELD(arg0, u16 *, 0x90) & 1) {
            M2C_FIELD(arg0, s16 *, 0x3B2) = 0xF;
        }
    }
}
