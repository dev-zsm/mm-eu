// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "overlays/0653.h"

extern M2C_UNK D_80C0551C;

void func_80000A6C(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x3E0) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x228) = &D_80C0551C;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
