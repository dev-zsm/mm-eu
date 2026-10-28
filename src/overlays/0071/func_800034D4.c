// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_800C3F18(s32, s32, s32, M2C_UNK *, u8 *, s32); /* extern */

void func_800034D4(u8 *arg0, s32 arg1) {
    s32 pad;
    M2C_UNK sp28;

    M2C_FIELD(arg0, f32 *, 0x88) = func_800C3F18(arg1, arg1 + 0x830, arg0 + 0x80, &sp28, arg0, arg0 + 0x24);
    M2C_FIELD(arg0, s8 *, 0xD0) = 0x32;
}
