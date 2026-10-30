// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800B8D6C(u8 *, M2C_UNK);             /* extern */

void func_80000380(Actor *thisx) {
    M2C_FIELD(thisx, M2C_UNK (**)(), 0x144)();
    func_800B8D6C(thisx, 0x20DD);
}
