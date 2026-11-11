// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0126.h"

void func_800B8C4C();
extern u8 D_808F16CC;

void func_80000DAC(u8 *arg0) {
    func_800B8C4C(arg0, 0x3862);
    M2C_FIELD(arg0, s32 *, 4) |= 0x30;
    M2C_FIELD(arg0, s32 *, 4) &= ~1;
    if (M2C_FIELD(arg0, u8 *, 0x1EC) == 0xA) {
        M2C_FIELD(arg0, s16 *, 0x1EE) = 3;
    }
    M2C_FIELD(arg0, u8 **, 0x188) = &D_808F16CC;
}
