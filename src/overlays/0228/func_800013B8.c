// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_800BE288();
extern u8 D_80969A48;

void func_800013B8(u8 *arg0) {
    M2C_FIELD(arg0, u8 *, 0x171) &= 0xFFFE;
    M2C_FIELD(arg0, u8 *, 0x172) |= 1;
    M2C_FIELD(arg0, s16 *, 0x14A) = 0x1E;
    M2C_FIELD(arg0, f32 *, 0x70) = 20.0f;
    func_800BE288(arg0, arg0 + 0x160);
    M2C_FIELD(arg0, u8 **, 0x144) = &D_80969A48;
}
