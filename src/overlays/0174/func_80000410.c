// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s16 func_800FF860();
void func_800FFCBC();

void func_80000410(u8 *arg0, u8 *arg1) {
    u8 *p = M2C_FIELD(arg1, u8 **, 0x1CCC);

    M2C_FIELD(arg0, s16 *, 0x32) = func_800FF860(arg0 + 0x24, p + 0x24, arg1);
    func_800FFCBC(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x32), 6, 0x3E8, 0xC8);
}
