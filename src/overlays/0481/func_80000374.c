// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80B1C158;

void func_80000374(u8 *arg0) {
    M2C_FIELD(arg0, u8 *, 0x159) = (u8) (M2C_FIELD(arg0, u8 *, 0x159) | 2);
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80B1C158;
    M2C_FIELD(arg0, f32 *, 0x68) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x74) = -2.0f;
}
