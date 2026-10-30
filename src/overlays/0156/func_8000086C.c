// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

void func_8000086C(Actor *thisx) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(thisx, s16 *, 0x166);
    if (temp_v0 > 0) {
        M2C_FIELD(thisx, s16 *, 0x166) = (s16) (temp_v0 - 1);
    }
    M2C_FIELD(thisx, M2C_UNK (**)(), 0x15C)();
}
