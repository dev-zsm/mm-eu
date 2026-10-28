// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80B1C6F0;

void func_80000918(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x21E) = 0;
    M2C_FIELD(arg0, f32 *, 0x74) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x68) = 0.0f;
    M2C_FIELD(arg0, s16 *, 0x21A) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80B1C6F0;
}
