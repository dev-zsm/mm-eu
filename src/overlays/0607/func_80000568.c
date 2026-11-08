// FLAGS: -O2 -g3 -mips2
#include "types.h"

void func_800FF384();
void func_800E26E8();

void func_80000568(s32 arg0, s32 arg1) {
    func_800FF384(arg0 + 0x1D6, arg0 + 0x24);
    func_800E26E8(arg1, arg1 + 0x18884, arg0 + 0x190);
}
