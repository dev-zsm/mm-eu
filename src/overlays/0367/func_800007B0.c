// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80A61DE8;

void func_800007B0(u8 *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x08000000);
    M2C_FIELD(arg0, s16 *, 0x2B2) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x2A8) = &D_80A61DE8;
}
