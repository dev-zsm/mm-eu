// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80000288(u8 *arg0) {
    M2C_FIELD(arg0, s8 *, 0x368) = 0;
    M2C_FIELD(arg0, u8 *, 0x365) = (u8) (M2C_FIELD(arg0, u8 *, 0x365) & 0xFFFB);
    M2C_FIELD(arg0, s32 *, 0x374) = (s32) (M2C_FIELD(arg0, s32 *, 0x374) | 0x8000);
    M2C_FIELD(arg0, s16 *, 0x190) = 0;
}
