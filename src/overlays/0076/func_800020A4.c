// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_8089BED8;

void func_800020A4(u8 *arg0) {
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    if (M2C_FIELD(arg0, f32 *, 0x68) > 0.0f) {
        M2C_FIELD(arg0, f32 *, 0x68) = 0.0f;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x284) = &D_8089BED8;
}
