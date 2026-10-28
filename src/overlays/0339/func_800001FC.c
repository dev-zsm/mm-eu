// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80A32E60;

void func_800001FC(u8 *arg0) {
    M2C_FIELD(arg0, s8 *, 0x14A) = 0;
    M2C_FIELD(arg0, u8 *, 0x14B) = (u8) (M2C_FIELD(arg0, u8 *, 0x14B) | 3);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~1);
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80A32E60;
}
