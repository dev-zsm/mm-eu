// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80975C90;

void func_80000BFC(u8 *arg0) {
    M2C_FIELD(arg0, u8 *, 0x461) = (u8) (M2C_FIELD(arg0, u8 *, 0x461) & 0xFFFE);
    M2C_FIELD(arg0, f32 *, 0xCC) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x5C) = 0.0f;
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~1);
    M2C_FIELD(arg0, s16 *, 0x2A0) = 0x3C;
    M2C_FIELD(arg0, M2C_UNK **, 0x290) = &D_80975C90;
}
