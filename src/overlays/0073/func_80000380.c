// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80893230();                            /* extern */

void func_80000380(u8 *arg0) {
    if (M2C_FIELD(arg0, s16 *, 0x1C) == -2) {
        if (M2C_FIELD(arg0, u16 *, 0x90) & 0x20) {
            M2C_FIELD(arg0, f32 *, 0x74) = 0.0f;
            func_80893230();
            return;
        }
        M2C_FIELD(arg0, f32 *, 0x74) = -1.0f;
    }
}
