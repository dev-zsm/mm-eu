// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_800B8C4C();
extern u8 D_8097ABA4;

void func_80001658(u8 *arg0) {
    if (M2C_FIELD(arg0, u16 *, 0x90) & 1) {
        M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    }
    func_800B8C4C(arg0, 0x389E);
    M2C_FIELD(arg0, u8 *, 0x3E4) = 0;
    M2C_FIELD(arg0, s16 *, 0x3DE) = 5;
    M2C_FIELD(arg0, u8 **, 0x228) = &D_8097ABA4;
}
