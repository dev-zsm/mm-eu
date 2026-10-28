// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern f32 D_80ABDC0C;
extern f32 D_80ABDC10;

void func_80000798(u8 *arg0) {
    f32 temp_f0;

    temp_f0 = (f32) M2C_FIELD(arg0, s16 *, 0x2A6);
    M2C_FIELD(arg0, f32 *, 0x70) = (f32) (temp_f0 * D_80ABDC0C);
    M2C_FIELD(arg0, s16 *, 0xC0) = (s16) (s32) (temp_f0 * D_80ABDC10);
}
