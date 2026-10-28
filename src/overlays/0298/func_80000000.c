// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800BAE44(s32, u8 *, s32, M2C_UNK, f32, f32, f32, s32, s32, s32, s32); /* extern */

s32 func_80000000(u8 *arg0, s32 arg1) {
    return func_800BAE44(arg1 + 0x1CA0, arg0, arg1, 0x13D, M2C_FIELD(arg0, f32 *, 0x24), M2C_FIELD(arg0, f32 *, 0x28), M2C_FIELD(arg0, f32 *, 0x2C), (s32) M2C_FIELD(arg0, s16 *, 0xBC), (s32) M2C_FIELD(arg0, s16 *, 0xBE), (s32) M2C_FIELD(arg0, s16 *, 0xC0), 1) != 0;
}
