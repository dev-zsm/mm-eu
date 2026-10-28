// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_808B2758;

void func_80001D14(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x18E) = 9;
    M2C_FIELD(arg0, u8 *, 0x24D) = (u8) (M2C_FIELD(arg0, u8 *, 0x24D) | 1);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808B2758;
    M2C_FIELD(arg0, f32 *, 0x160) = -1.0f;
}
