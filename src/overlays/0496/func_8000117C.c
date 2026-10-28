// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80B474E4;

void func_8000117C(u8 *arg0) {
    M2C_FIELD(arg0, s8 *, 0x2C0) = 9;
    M2C_FIELD(arg0, u8 *, 0x2BD) = (u8) (M2C_FIELD(arg0, u8 *, 0x2BD) | 4);
    M2C_FIELD(arg0, s32 *, 0x2CC) = (s32) (M2C_FIELD(arg0, s32 *, 0x2CC) & 0xFFFF7FFF);
    M2C_FIELD(arg0, u8 *, 0x2BC) = (u8) (M2C_FIELD(arg0, u8 *, 0x2BC) | 1);
    M2C_FIELD(arg0, s16 *, 0x20A) = 0x800;
    M2C_FIELD(arg0, M2C_UNK **, 0x200) = &D_80B474E4;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
