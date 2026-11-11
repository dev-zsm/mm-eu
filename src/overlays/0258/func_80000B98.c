// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0258.h"

void func_800B8C4C();
extern u8 D_8098BBB4;

void func_80000B98(u8 *arg0) {
    func_800B8C4C(arg0, 0x30A0);
    M2C_FIELD(arg0, s16 *, 0x50A) = M2C_FIELD(arg0, s16 *, 0x32) + 0x8000;
    M2C_FIELD(arg0, s16 *, 0x358) = 2;
    M2C_FIELD(arg0, s16 *, 0x35C) = 0;
    M2C_FIELD(arg0, u8 **, 0x2A8) = &D_8098BBB4;
    M2C_FIELD(arg0, f32 *, 0x70) = 2.0f;
}
