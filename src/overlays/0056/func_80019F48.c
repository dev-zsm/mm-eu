// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80838168();

s32 func_80019F48(s32 arg0, u8 *arg1) {
    s32 v = M2C_FIELD(arg1, s32 *, 0xA74);

    if (v & 0x20) {
        M2C_FIELD(arg1, s32 *, 0xA74) = v & ~0x20;
        M2C_FIELD(arg1, u8 *, 0x14A) = 0x14;
        M2C_FIELD(arg1, u8 *, 0xAA5) = 5;
        func_80838168(arg1, arg0);
        return 1;
    }
    return 0;
}
