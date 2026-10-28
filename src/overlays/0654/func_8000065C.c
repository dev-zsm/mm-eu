// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8013B284(s32, M2C_UNK, M2C_UNK, u8 *); /* extern */

void func_8000065C(u8 *arg0, M2C_UNK arg1) {
    func_8013B284(arg0 + 0x18C, 3, 7, arg0);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 1);
}
