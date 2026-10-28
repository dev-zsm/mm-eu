// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_800FEB44(s16);                             /* extern */
f32 func_800FEB84(s16);                             /* extern */
extern f32 D_808EFBDC;
extern f32 D_808EFBE0;
extern f32 D_808EFBE4;

void func_80001AB0(u8 *arg0, s16 arg1, f32 arg2, f32 arg3) {
    M2C_FIELD(arg0, f32 *, 0x58) = (f32) (((func_800FEB84(arg1) * arg2) + 1.5f) * D_808EFBDC);
    M2C_FIELD(arg0, f32 *, 0x5C) = (f32) (((func_800FEB44(arg1) * arg3) + 0.75f) * D_808EFBE0);
    M2C_FIELD(arg0, f32 *, 0x60) = (f32) (D_808EFBE4 - M2C_FIELD(arg0, f32 *, 0x58));
}
