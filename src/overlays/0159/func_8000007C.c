// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern f32 D_809279C0;

void func_8000007C(u8 *arg0) {
    M2C_FIELD(arg0, f32 *, 0x1DC) = (f32) (M2C_FIELD(arg0, f32 *, 0x58) * D_809279C0);
}
