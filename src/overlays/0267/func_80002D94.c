// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0267.h"

void func_800BC8F4();
extern u8 D_80999C18;

void func_80002D94(u8 *arg0, s32 arg1, u16 arg2) {
    M2C_FIELD(arg0, u8 **, 0x420) = &D_80999C18;
    M2C_FIELD(arg0, u16 *, 0x14A) = arg2;
    M2C_FIELD(arg0, s16 *, 0x14C) = 0x1E;
    func_800BC8F4(arg0, 0, 0x78, 0, arg2);
}
