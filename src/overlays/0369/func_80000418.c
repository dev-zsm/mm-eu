// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800FEE3C(u8 *, f32, M2C_UNK, u8 *);    /* extern */
M2C_UNK func_80A69DDC(u8 *);                      /* extern */

void func_80000418(u8 *arg0, M2C_UNK arg1) {
    func_800FEE3C(arg0 + 0x168, M2C_FIELD(arg0, f32 *, 0xC) - 90.0f, 0x3F666666, arg0);
    if (func_800FEE3C(arg0 + 0x16C, M2C_FIELD(arg0, f32 *, 0xC), 0x3F666666, arg0) != 0) {
        func_80A69DDC(arg0);
    }
}
