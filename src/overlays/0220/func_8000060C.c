// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern f32 D_80964C34;

void func_8000060C(s32 arg0, M2C_UNK arg1, u8 *arg2) {
    M2C_FIELD(arg2, s16 *, 0x40) = (s16) (s32) ((f32) M2C_FIELD(arg2, s16 *, 0x40) * D_80964C34);
}
