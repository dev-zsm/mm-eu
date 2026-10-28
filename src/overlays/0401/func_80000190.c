// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80138F50(s32, u8 *, u8 *, u8 *); /* extern */
extern M2C_UNK D_80AA9818;

void func_80000190(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0x160) = 0x14;
    func_80138F50(arg1 + 0x187B0, arg0 + 0x24, arg0 + 0xEC, arg0 + 0xF8);
    func_800B8C4C(arg0, 0x2862);
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_80AA9818;
}
