// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_809FCDE4;

void func_80001340(u8 *arg0) {
    if (M2C_FIELD(arg0, s16 *, 0x3C6) == 4) {
        M2C_FIELD(arg0, s16 *, 0x3B4) = 0x5A;
    } else {
        M2C_FIELD(arg0, s16 *, 0x3C6) = 7;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x230) = &D_809FCDE4;
}
