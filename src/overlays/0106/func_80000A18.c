// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "overlays/0106.h"

extern M2C_UNK D_808CA1BC;

void func_80000A18(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x1C) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_808CA1BC;
    M2C_FIELD(arg0, f32 *, 0x70) = 5.0f;
}
