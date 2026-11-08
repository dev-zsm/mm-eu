// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0239.h"

extern M2C_UNK D_80977124;

void func_800020A0(Actor *thisx) {
    M2C_FIELD(thisx, f32 *, 0x70) = 0.0f;
    if (M2C_FIELD(thisx, f32 *, 0x68) > 0.0f) {
        M2C_FIELD(thisx, f32 *, 0x68) = 0.0f;
    }
    M2C_FIELD(thisx, M2C_UNK **, 0x290) = &D_80977124;
}
