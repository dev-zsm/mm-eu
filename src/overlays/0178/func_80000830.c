// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80000830(u8 *arg0, u8 *arg1) {
    if (M2C_FIELD(arg1, u8 *, 0x1F2C) == 0) {
        M2C_FIELD(arg0, f32 *, 0x17C) = 1.0f;
    } else {
        M2C_FIELD(arg0, f32 *, 0x17C) = 4.0f;
    }
    M2C_FIELD(arg0, M2C_UNK (**)(), 0x144)();
}
