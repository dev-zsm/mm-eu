// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80A03A04;

void func_80001270(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x4A0) = &D_80A03A04;
}
