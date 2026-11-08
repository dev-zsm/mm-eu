// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

float fabsf(float);
#pragma intrinsic (fabsf)

void func_808D7494();
extern u8 D_808D7D48;
extern f32 D_808D7E50[];

void func_80000744(u8 *arg0) {
    if (fabsf(M2C_FIELD(arg0, f32 *, 0xF4)) < D_808D7E50[M2C_FIELD(arg0, s16 *, 0x14E)]) {
        M2C_FIELD(arg0, u8 **, 0x144) = &D_808D7D48;
        M2C_FIELD(arg0, s32 *, 4) |= 0x10;
        func_808D7494();
    }
}
