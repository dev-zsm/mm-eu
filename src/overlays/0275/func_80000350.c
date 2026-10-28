// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_809AB578;
extern M2C_UNK D_809AC008;

void func_80000350(u8 *arg0, u8 *arg1) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg1, s16 *, 0xA4);
    if (temp_v0 == 0x24) {
        M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_809AB578;
        return;
    }
    if (temp_v0 == 0x20) {
        M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_809AC008;
    }
}
