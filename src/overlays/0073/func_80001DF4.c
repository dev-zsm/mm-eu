// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0073.h"

void func_800B8C4C();
extern u8 D_80894D60;

void func_80001DF4(u8 *arg0) {
    M2C_FIELD(arg0, u8 *, 0x2B9) = 0;
    M2C_FIELD(arg0, f32 *, 0x68) = 13.0f;
    func_800B8C4C(arg0, 0x3888);
    M2C_FIELD(arg0, u16 *, 0x90) &= 0xFFFE;
    M2C_FIELD(arg0, u8 *, 0x3BD) &= 0xFFFE;
    M2C_FIELD(arg0, u8 **, 0x2B4) = &D_80894D60;
}
