// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80A55AB8;

void func_80000684(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, f32 *, 0x164) = 180.0f;
    M2C_FIELD(arg0, f32 *, 0x160) = 180.0f;
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_80A55AB8;
    M2C_FIELD(arg0, f32 *, 0x28) = (f32) (M2C_FIELD(arg0, f32 *, 0xC) + 180.0f);
}
