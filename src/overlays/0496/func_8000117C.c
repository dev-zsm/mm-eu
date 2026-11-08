// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0496.h"

extern M2C_UNK D_80B474E4;

void func_8000117C(Actor *thisx) {
    M2C_FIELD(thisx, s8 *, 0x2C0) = 9;
    M2C_FIELD(thisx, u8 *, 0x2BD) = (u8) (M2C_FIELD(thisx, u8 *, 0x2BD) | 4);
    M2C_FIELD(thisx, s32 *, 0x2CC) = (s32) (M2C_FIELD(thisx, s32 *, 0x2CC) & 0xFFFF7FFF);
    M2C_FIELD(thisx, u8 *, 0x2BC) = (u8) (M2C_FIELD(thisx, u8 *, 0x2BC) | 1);
    M2C_FIELD(thisx, s16 *, 0x20A) = 0x800;
    M2C_FIELD(thisx, M2C_UNK **, 0x200) = &D_80B474E4;
    M2C_FIELD(thisx, f32 *, 0x70) = 0.0f;
}
