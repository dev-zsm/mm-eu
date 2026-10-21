// FLAGS: -O1 -g0 -mips2
#include "types.h"

extern u32 D_80098050;
u32 func_80091C00(void);
void func_80091C70(u32);

void func_80091770(u32 arg0) {
    register u32 saveMask;

    saveMask = func_80091C00();
    D_80098050 &= ~(arg0 & ~0x401);
    func_80091C70(saveMask);
}
