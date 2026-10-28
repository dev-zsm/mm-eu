// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80A67C18;

void func_80001DB4(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x1A4) = &D_80A67C18;
}
