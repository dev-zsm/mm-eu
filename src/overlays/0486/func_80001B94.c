// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_80B244BC();                            /* extern */
M2C_UNK func_80B24650();                            /* extern */

void func_80001B94(Actor *thisx) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(thisx, u16 *, 0x1CE);
    if (!(temp_v0 & 0x200)) {
        if (temp_v0 & 0x20) {
            func_80B244BC();
            return;
        }
        func_80B24650();
    }
}
