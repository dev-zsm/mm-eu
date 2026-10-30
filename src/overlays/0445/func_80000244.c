// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

void func_80000244(Actor *thisx) {
    u16 temp_v0;

    M2C_FIELD(thisx, M2C_UNK (**)(), 0x15C)();
    temp_v0 = M2C_FIELD(thisx, u16 *, 0x1CC);
    M2C_FIELD(thisx, u16 *, 0x1CC) = (u16) (temp_v0 & 0xFFFE);
    M2C_FIELD(thisx, u16 *, 0x1CE) = temp_v0;
}
