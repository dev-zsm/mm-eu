// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80000A00(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, s16 *, 0x3C0) = (s16) (M2C_FIELD(arg0, s16 *, 0x3C0) + 0x6E);
    if (M2C_FIELD(arg0, s16 *, 0x3C0) >= 0xFA1) {
        M2C_FIELD(arg0, s16 *, 0x3C0) = 0xFA0;
    }
}
