// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_8090D418;

void func_80001354(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_8090D418;
}
