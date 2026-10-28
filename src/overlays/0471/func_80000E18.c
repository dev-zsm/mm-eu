// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern f32 D_80B0AC44;
extern f32 D_80B0AD50;

void func_80000E18(u8 *arg0) {
    if (M2C_FIELD(arg0, f32 *, 0x70) < 3.0f) {
        D_80B0AC44 = D_80B0AD50;
        return;
    }
    D_80B0AC44 = 1.0f;
}
