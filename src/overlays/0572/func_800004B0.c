// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_80BB92A0(u8 *);                      /* extern */

void func_800004B0(Actor *thisx) {
    M2C_FIELD(thisx, M2C_UNK (**)(), 0x15C)();
    func_80BB92A0(thisx);
}
