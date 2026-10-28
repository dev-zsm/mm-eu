// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(f32, M2C_UNK);                /* extern */

void func_80000438(u8 *arg0, f32 arg1) {
    M2C_FIELD(arg0, f32 *, 0x70) = arg1;
    func_800B8C4C(arg1, 0x3990);
}
