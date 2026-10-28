// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80000648(u8 *arg0) {
    M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x160), s16 *, 0x30) = (s16) (s32) M2C_FIELD(arg0, f32 *, 0x24);
    M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x160), s16 *, 0x32) = (s16) (s32) M2C_FIELD(arg0, f32 *, 0x28);
    M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x160), s16 *, 0x34) = (s16) (s32) M2C_FIELD(arg0, f32 *, 0x2C);
}
