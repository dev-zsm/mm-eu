// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_8000049C(u8 *arg0, u8 *arg1) {
    M2C_FIELD(arg0, s16 *, 0) = (s16) (s32) M2C_FIELD(arg1, f32 *, 0);
    M2C_FIELD(arg0, s16 *, 2) = (s16) (s32) M2C_FIELD(arg1, f32 *, 4);
    M2C_FIELD(arg0, s16 *, 4) = (s16) (s32) M2C_FIELD(arg1, f32 *, 8);
}
