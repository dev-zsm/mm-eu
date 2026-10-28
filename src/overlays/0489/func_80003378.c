// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800E0FAC(M2C_UNK, s32, u8 *, M2C_UNK); /* extern */

void func_80003378(u8 *arg0, M2C_UNK arg1) {
    u8 *temp_v0;

    func_800E0FAC(arg1, arg0 + 0x2A0, arg0, arg1);
    temp_v0 = M2C_FIELD(arg0, u8 **, 0x124);
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, s32 *, 0x120) = 0;
    }
}
