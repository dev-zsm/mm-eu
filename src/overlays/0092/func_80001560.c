// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0092.h"

extern M2C_UNK D_808B1F94;

void func_80001560(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x18E) = 8;
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808B1F94;
    M2C_FIELD(arg0, f32 *, 0x160) = 0.0f;
}
