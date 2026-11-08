// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0076.h"

extern M2C_UNK D_8089BED8;

void func_800020A4(Actor *thisx) {
    M2C_FIELD(thisx, f32 *, 0x70) = 0.0f;
    if (M2C_FIELD(thisx, f32 *, 0x68) > 0.0f) {
        M2C_FIELD(thisx, f32 *, 0x68) = 0.0f;
    }
    M2C_FIELD(thisx, M2C_UNK **, 0x284) = &D_8089BED8;
}
