// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "overlays/0175.h"

void func_80001B0C(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK (**)(), 0x190)();
}
