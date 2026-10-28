// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80008FC0(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, s32 *, 0x208) = 0;
    M2C_FIELD(arg0, s32 *, 0x144) = 0x15;
    M2C_FIELD(arg0, s32 *, 0x3E0) = -1;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
