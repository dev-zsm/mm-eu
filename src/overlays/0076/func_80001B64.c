// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0076.h"

void func_800B8C4C();
extern u8 D_8089B9C8;

void func_80001B64(u8 *arg0) {
    M2C_FIELD(arg0, u16 *, 0x90) &= 0xFFFE;
    M2C_FIELD(arg0, f32 *, 0x70) = 8.0f;
    M2C_FIELD(arg0, f32 *, 0x68) = 16.0f;
    func_800B8C4C(arg0, 0x382F);
    M2C_FIELD(arg0, s16 *, 0x290) = 0;
    M2C_FIELD(arg0, s16 *, 0x292) = -1;
    M2C_FIELD(arg0, u8 **, 0x284) = &D_8089B9C8;
}
