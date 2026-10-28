// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_808FCBF8;

void func_80000E38(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, u16 *, 0x160) = (u16) (M2C_FIELD(arg0, u16 *, 0x160) | 8);
    M2C_FIELD(arg0, f32 *, 0x6C) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x68) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x64) = 0.0f;
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_808FCBF8;
    M2C_FIELD(arg0, f32 *, 0x74) = -1.0f;
}
