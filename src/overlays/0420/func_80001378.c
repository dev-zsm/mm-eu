#include "types.h"
#include "m2c_compat.h"

extern f32 D_80ABA6C4;
extern f32 D_80ABA6C8;

void func_80001378(u8 *arg0) {
    if ((M2C_FIELD(arg0, f32 *, 0xC) + 60.0f) < M2C_FIELD(arg0, f32 *, 0x28)) {
        M2C_FIELD(arg0, f32 *, 0x68) = (f32) D_80ABA6C4;
        return;
    }
    if (M2C_FIELD(arg0, f32 *, 0x28) <= (M2C_FIELD(arg0, f32 *, 0xC) + 50.0f)) {
        M2C_FIELD(arg0, f32 *, 0x68) = (f32) D_80ABA6C8;
    }
}
