// FLAGS: -O2 -g3 -mips2
#include "types.h"

void func_801377D0();
extern u8 D_6000350;
extern u8 D_80897468;

void func_80000DD0(u8 *arg0) {
    func_801377D0(arg0 + 0x144, &D_6000350, arg0);
    *(u8 *)(arg0 + 0x478) &= 0xFFFE;
    *(u8 **)(arg0 + 0x2A8) = &D_80897468;
}
