// FLAGS: -O2 -g0 -mips2
#include "os_internal.h"

void func_8008019C(void) {
    func_80080180((u32 *)D_80000500, 0x25800, 0x10001);
    osViSetMode(&D_8009B610);
    osViSetSpecialFeatures(D_80096CCC);
    osViSwapBuffer(D_80000500);
    osViBlack(0);
}
