// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80879D2C;

void func_80000EEC(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x190) = 0x96;
    M2C_FIELD(arg0, s16 *, 0x192) = 0x954;
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80879D2C;
    M2C_FIELD(arg0, f32 *, 0x160) = 1.0f;
}
