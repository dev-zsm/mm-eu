// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_80AB4FA4(u8 *);                      /* extern */

void func_80000B7C(Actor *thisx) {
    M2C_FIELD(thisx, M2C_UNK (**)(), 0x15C)();
    if (M2C_FIELD(thisx, s16 *, 0x33C) == 1) {
        func_80AB4FA4(thisx);
    }
}
