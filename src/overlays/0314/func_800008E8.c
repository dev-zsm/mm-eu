// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80A17850;

void func_800008E8(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x206) = 4;
    M2C_FIELD(arg0, M2C_UNK **, 0x200) = &D_80A17850;
    M2C_FIELD(arg0, f32 *, 0x160) = 2.0f;
}
