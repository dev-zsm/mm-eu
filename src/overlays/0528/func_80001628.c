// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern u8 D_801E6F10;
void func_80151DF4();

void func_80001628(s32 arg0, s32 arg1) {
    func_80151DF4(arg1, D_801E6F10 == 2 ? 0x128C : 0x128B, arg0);
}
