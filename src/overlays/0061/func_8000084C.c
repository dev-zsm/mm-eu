// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80866810;

void func_8000084C(u8 *arg0, M2C_UNK arg1) {
    if (M2C_FIELD(arg0, f32 *, 0x98) < 120.0f) {
        M2C_FIELD(arg0, M2C_UNK **, 0x1C8) = &D_80866810;
    }
}
