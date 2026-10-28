// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_8000066C(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK (**)(), 0x1AC)();
}
