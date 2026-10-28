// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_809473C0;

void func_800011DC(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x1D4) = &D_809473C0;
}
