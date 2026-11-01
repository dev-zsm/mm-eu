// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0144.h"

extern M2C_UNK D_8090FAC4;

void func_800016A4(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x2FC) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x2F0) = &D_8090FAC4;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
