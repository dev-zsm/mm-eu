// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80B46AD4;

void func_80000794(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x20A) = 0x1000;
    M2C_FIELD(arg0, M2C_UNK **, 0x200) = &D_80B46AD4;
    M2C_FIELD(arg0, f32 *, 0x214) = 200.0f;
    M2C_FIELD(arg0, f32 *, 0x68) = 0.0f;
}
