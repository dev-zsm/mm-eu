// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80992908();
extern u8 D_80994100;

void func_80001A88(u8 *arg0) {
    func_80992908(arg0, 7);
    M2C_FIELD(arg0, u8 *, 0x36D) &= 0xFFFB;
    M2C_FIELD(arg0, s16 *, 0x288) = 0x1E;
    M2C_FIELD(arg0, s16 *, 0x27C) = 9;
    M2C_FIELD(arg0, u8 **, 0x278) = &D_80994100;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
