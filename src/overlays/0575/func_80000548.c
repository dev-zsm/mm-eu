// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FEE3C(s32, M2C_UNK, M2C_UNK);       /* extern */
f32 func_800FFAD8(u8 *, f32, M2C_UNK, s32, f32);  /* extern */
M2C_UNK func_80BBAA04(u8 *);                      /* extern */

void func_80000548(u8 *arg0, M2C_UNK arg1) {
    func_800FEE3C(arg0 + 0x68, 0x40800000, 0x3F000000);
    if (func_800FFAD8(arg0 + 0x28, M2C_FIELD(arg0, f32 *, 0xC) + -220.0f, 0x3F000000, M2C_FIELD(arg0, s32 *, 0x68), 1.0f) < 0.5f) {
        func_80BBAA04(arg0);
    }
}
