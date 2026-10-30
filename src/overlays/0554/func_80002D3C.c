// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_80BA4390();                            /* extern */
M2C_UNK func_80BA445C();                            /* extern */

void func_80002D3C(Actor *thisx) {
    if (M2C_FIELD(thisx, u16 *, 0x1DC) & 1) {
        func_80BA445C();
        return;
    }
    func_80BA4390();
}
