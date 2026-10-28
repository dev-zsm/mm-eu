// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80000D2C(u8 *arg0) {
    if (M2C_FIELD(arg0, f32 *, 0x2C8) > 0.0f) {
        M2C_FIELD(arg0, f32 *, 0x28) = (f32) (M2C_FIELD(arg0, f32 *, 0xC) - 10.0f);
        return;
    }
    M2C_FIELD(arg0, f32 *, 0x28) = (f32) (M2C_FIELD(arg0, f32 *, 0x88) + 20.0f);
}
