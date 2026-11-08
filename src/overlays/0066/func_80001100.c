// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_800FF72C();
void func_808742A8();

void func_80001100(u8 *arg0, u8 *arg1) {
    u8 *p = M2C_FIELD(arg1, u8 **, 0x1CCC);

    if (func_800FF72C(arg0 + 8, p + 0x24) < M2C_FIELD(arg0, f32 *, 0x2C4)) {
        func_808742A8(arg0, arg1);
    }
}
