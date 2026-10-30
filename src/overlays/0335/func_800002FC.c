// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

void func_800002FC(Actor *thisx) {
    M2C_FIELD(thisx, M2C_UNK (**)(), 0x1C8)();
}
