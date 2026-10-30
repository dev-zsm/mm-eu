// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

void func_80000FF0(Actor *thisx) {
    M2C_FIELD(thisx, M2C_UNK (**)(), 0x160)();
}
