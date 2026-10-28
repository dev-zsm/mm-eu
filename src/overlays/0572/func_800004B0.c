// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80BB92A0(u8 *);                      /* extern */

void func_800004B0(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK (**)(), 0x15C)();
    func_80BB92A0(arg0);
}
