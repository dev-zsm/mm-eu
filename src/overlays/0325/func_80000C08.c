// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80A21E4C;

void func_80000C08(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x390) = &D_80A21E4C;
}
