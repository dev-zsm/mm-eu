// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80B48140;

void func_80001E08(u8 *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & 0xFFFEFFFE);
    M2C_FIELD(arg0, M2C_UNK **, 0x200) = &D_80B48140;
}
