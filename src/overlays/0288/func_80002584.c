// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0288.h"

void func_800B8C4C();
void func_800BC8F4();
extern u8 D_809D57EC;

void func_80002584(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, u8 **, 0x170) = &D_809D57EC;
    func_800B8C4C(arg0, 0x3807);
    M2C_FIELD(arg0, s16 *, 0x162) = 0x50;
    func_800BC8F4(arg0, 0, 0x78, 0, 0x50);
}
