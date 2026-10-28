// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80137934(s32, M2C_UNK *, M2C_UNK);     /* extern */
extern M2C_UNK D_6005700;
extern M2C_UNK D_809780E0;

void func_80003040(u8 *arg0) {
    func_80137934(arg0 + 0x144, &D_6005700, 0xC0800000);
    func_800B8C4C(arg0, 0x383C);
    M2C_FIELD(arg0, M2C_UNK **, 0x290) = &D_809780E0;
}
