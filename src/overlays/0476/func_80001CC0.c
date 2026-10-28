// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_801A81E8(s32, M2C_UNK);                /* extern */
extern M2C_UNK D_80B13128;

void func_80001CC0(u8 *arg0) {
    func_801A81E8(arg0 + 0xEC, 0x31E8);
    func_800B8C4C(arg0, 0x38EC);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80B13128;
}
