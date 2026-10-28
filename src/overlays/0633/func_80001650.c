// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80BF6B90;

void func_80001650(u8 *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~1);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80BF6B90;
    M2C_FIELD(arg0, f32 *, 0x74) = -0.5f;
}
