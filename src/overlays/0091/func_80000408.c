// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_808AF804;

void func_80000408(u8 *arg0) {
    func_800B8C4C(arg0, 0x3845);
    func_800B8C4C(arg0, 0x3848);
    M2C_FIELD(arg0, s16 *, 0x238) = 0x12C;
    M2C_FIELD(arg0, M2C_UNK **, 0x230) = &D_808AF804;
}
