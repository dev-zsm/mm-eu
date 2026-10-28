// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_800B3F30;
extern M2C_UNK D_80895548;

void func_800025F8(u8 *arg0) {
    M2C_FIELD(arg0, u8 *, 0x3BD) = (u8) (M2C_FIELD(arg0, u8 *, 0x3BD) & 0xFFFE);
    M2C_FIELD(arg0, M2C_UNK **, 0xC8) = &D_800B3F30;
    M2C_FIELD(arg0, M2C_UNK **, 0x2B4) = &D_80895548;
    M2C_FIELD(arg0, f32 *, 0x160) = 1.0f;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
