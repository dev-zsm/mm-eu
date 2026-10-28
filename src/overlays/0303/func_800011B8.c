// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80A07064;

void func_800011B8(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_80A07064;
    M2C_FIELD(arg0, s16 *, 0x174) = 0;
    M2C_FIELD(arg0, s16 *, 0x176) = 0;
    M2C_FIELD(arg0, s16 *, 0x178) = 0;
    M2C_FIELD(arg0, s16 *, 0x172) = 0;
    M2C_FIELD(arg0, f32 *, 0x68) = 0.0f;
}
