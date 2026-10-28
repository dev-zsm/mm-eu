// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80AFD34C;

void func_80001B00(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x280) = &D_80AFD34C;
    M2C_FIELD(arg0, f32 *, 0x2A0) = 0.0f;
}
