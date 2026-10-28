// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8087D548();                            /* extern */

void func_800026BC(u8 *arg0) {
    M2C_FIELD(arg0, f32 *, 0x1BC) = 0.0f;
    func_8087D548();
    M2C_FIELD(arg0, s32 *, 0x1E8) = (s32) (M2C_FIELD(arg0, s32 *, 0x1E8) & ~0x1000);
}
