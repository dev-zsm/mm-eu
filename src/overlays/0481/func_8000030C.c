// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_800FFAD8(u8 *, s32, M2C_UNK, M2C_UNK, f32); /* extern */
M2C_UNK func_80B1BFE8(u8 *);                      /* extern */

void func_8000030C(u8 *arg0, M2C_UNK arg1) {
    if (func_800FFAD8(arg0 + 0x28, M2C_FIELD(arg0, s32 *, 0xC), 0x3ECCCCCD, 0x42C80000, 10.0f) == 0.0f) {
        func_80B1BFE8(arg0);
    }
}
