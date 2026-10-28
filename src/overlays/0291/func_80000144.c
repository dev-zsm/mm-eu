// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_800FEB84(s16);                             /* extern */

void func_80000144(u8 *arg0, u8 *arg1) {
    M2C_FIELD(arg0, f32 *, 0xC4) = (f32) (func_800FEB84((s16) (M2C_FIELD(arg1, s32 *, 0x18840) * 0x3E8)) * 15.0f);
}
