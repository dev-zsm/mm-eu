// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80A0D438;

void func_800011A0(u8 *arg0) {
    M2C_FIELD(arg0, s32 *, 0x2D0) = 0xF7CF7FFF;
    M2C_FIELD(arg0, u8 *, 0x2C0) = (u8) (M2C_FIELD(arg0, u8 *, 0x2C0) | 1);
    M2C_FIELD(arg0, s16 *, 0xC0) = 0x680;
    M2C_FIELD(arg0, s16 *, 0x29E) = 0xF;
    M2C_FIELD(arg0, M2C_UNK **, 0x298) = &D_80A0D438;
    M2C_FIELD(arg0, f32 *, 0x2A8) = 1.0f;
}
