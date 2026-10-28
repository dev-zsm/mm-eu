// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80877CD0;

void func_80001F24(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x2FC) = &D_80877CD0;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
