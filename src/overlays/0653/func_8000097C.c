// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80C0543C;

void func_8000097C(u8 *arg0) {
    if (M2C_FIELD(arg0, u16 *, 0x90) & 1) {
        M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x228) = &D_80C0543C;
}
