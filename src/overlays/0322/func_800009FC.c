// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800EE03C(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_800F1D6C(s8);                          /* extern */
extern M2C_UNK D_80A1F350;

void func_800009FC(u8 *arg0, M2C_UNK arg1) {
    if (func_800EE03C(arg1, 0x64, arg1) == 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x14C) = &D_80A1F350;
        func_800F1D6C(M2C_FIELD(arg0, s8 *, 0x38));
    }
}
