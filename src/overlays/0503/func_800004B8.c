// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800FEE3C(u8 *, f32, M2C_UNK, u8 *);    /* extern */
M2C_UNK func_80B53A60(u8 *);                      /* extern */

void func_800004B8(u8 *arg0, M2C_UNK arg1) {
    if (func_800FEE3C(arg0 + 0x28, M2C_FIELD(arg0, f32 *, 0xC) + 58.0f, 0x40A00000, arg0) != 0) {
        func_80B53A60(arg0);
    }
}
