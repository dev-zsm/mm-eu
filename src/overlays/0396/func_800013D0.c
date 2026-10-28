// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80AA3DB4;

void func_800013D0(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80AA3DB4;
}
