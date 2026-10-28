// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_80986E3C;

void func_80000000(u8 *arg0, M2C_UNK arg1) {
    func_800B6564(arg0, 0x3C75C28F);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80986E3C;
}
