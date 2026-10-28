// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800FEE3C(u8 *, s32, M2C_UNK, u8 *);    /* extern */
extern M2C_UNK D_809AEABC;

void func_8000060C(u8 *arg0, M2C_UNK arg1) {
    if (func_800FEE3C(arg0 + 0x28, M2C_FIELD(arg0, s32 *, 0xC), 0x3F800000, arg0) != 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_809AEABC;
        M2C_FIELD(arg0, f32 *, 0x68) = 0.0f;
    }
}
