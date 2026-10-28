// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_808BF858;

void func_80000F1C(u8 *arg0) {
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    if (M2C_FIELD(arg0, f32 *, 0x68) > 0.0f) {
        M2C_FIELD(arg0, f32 *, 0x68) = 0.0f;
    }
    M2C_FIELD(arg0, f32 *, 0x74) = -2.0f;
    M2C_FIELD(arg0, M2C_UNK **, 0x248) = &D_808BF858;
}
