// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80A28A48;
extern s32 D_80A299D0;

void func_800007C0(u8 *arg0) {
    M2C_FIELD(arg0, u8 *, 0x194) = (u8) (M2C_FIELD(arg0, u8 *, 0x194) | 1);
    M2C_FIELD(arg0, s16 *, 0x14C) = 0x12C;
    M2C_FIELD(arg0, f32 *, 0x70) = 4.0f;
    D_80A299D0 += 1;
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80A28A48;
}
