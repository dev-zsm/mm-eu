// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80134AE8(M2C_UNK *, u8 *);               /* extern */
extern M2C_UNK D_6000E64;
extern M2C_UNK D_808C5EFC;

void func_80001848(u8 *arg0) {
    f32 temp_f6;

    temp_f6 = (f32) func_80134AE8(&D_6000E64, arg0);
    M2C_FIELD(arg0, s16 *, 0x2EE) = 0;
    M2C_FIELD(arg0, f32 *, 0x154) = temp_f6;
    M2C_FIELD(arg0, s16 *, 0x2EC) = -1;
    M2C_FIELD(arg0, s8 *, 0x18C) = 1;
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808C5EFC;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
