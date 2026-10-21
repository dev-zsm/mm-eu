// FLAGS: -O1 -g3 -mips2
#include "types.h"

extern s32 D_80098050;
s32 func_80091C00(void);
void func_80091C70(s32 a);

void func_80091770(s32 a) {
    u32 r = func_80091C00(); D_80098050 &= ~(a & ~0x401); func_80091C70(r);
}
