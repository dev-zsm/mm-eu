// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern u8 D_801E7E32;
extern M2C_UNK D_80BEB508;

void func_8000022C(u8 *arg0) {
    if (!(D_801E7E32 & 0x80)) {
        M2C_FIELD(arg0, s32 *, 0x13C) = 0;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x190) = &D_80BEB508;
}
