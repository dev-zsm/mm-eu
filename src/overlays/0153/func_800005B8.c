// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FF34C(s32, s32, u8 *);            /* extern */

void func_800005B8(u8 *arg0) {
    func_800FF34C(arg0 + 0x1BC, M2C_FIELD(arg0, s32 *, 0x1D4), arg0);
}
