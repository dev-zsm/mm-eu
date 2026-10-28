// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8D6C(u8 *, M2C_UNK);             /* extern */

void func_80000380(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK (**)(), 0x144)();
    func_800B8D6C(arg0, 0x20DD);
}
