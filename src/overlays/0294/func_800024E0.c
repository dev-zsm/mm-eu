// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern u8 D_801E7DFA;

void func_800024E0(u8 *arg0, u8 *arg1, s32 arg2) {
    if ((D_801E7DFA & 0x80) || (M2C_FIELD(arg1, u8 *, 0x1CA5) & 1) || (arg2 != 0)) {
        M2C_FIELD(arg0, s16 *, 0x272) = 0x12C;
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x272) = 0x17C;
}
