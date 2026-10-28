// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80979DA8;

void func_8000089C(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x228) = &D_80979DA8;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
