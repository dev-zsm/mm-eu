// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0274.h"

extern u8 D_809AA040;
extern f32 D_809AAF88;
extern f32 D_809AAF8C;

void func_80000B24(u8 *arg0) {
    M2C_FIELD(arg0, s32 *, 0x13C) = 0;
    M2C_FIELD(arg0, s32 *, 4) |= 0x10;
    M2C_FIELD(arg0, s32 *, 4) |= 0x08000000;
    M2C_FIELD(arg0, s32 *, 4) &= ~1;
    M2C_FIELD(arg0, f32 *, 0x24) = D_809AAF88;
    M2C_FIELD(arg0, f32 *, 0x2C) = D_809AAF8C;
    M2C_FIELD(arg0, s16 *, 0x29C) = 3;
    M2C_FIELD(arg0, u8 **, 0x284) = &D_809AA040;
}
