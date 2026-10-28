// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BC8F4(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
extern M2C_UNK D_80913A88;

void func_80000A2C(u8 *arg0) {
    func_800B8C4C(arg0, 0x2881);
    func_800BC8F4(arg0, 0x4000, 0xFF, 0, 0x28);
    M2C_FIELD(arg0, s16 *, 0x220) = 0x28;
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80913A88;
}
