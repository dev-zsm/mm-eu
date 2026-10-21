// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern void func_8008C380(void);
extern s32 func_8008FEA0(s32, s32, s32);
extern s32 func_8008C3C4(void);

s32 func_80092250(s32 a0, s32 a1, s32 a2) {
    volatile s32 sp1C;

    func_8008C380();
    func_8008FEA0(a0, a1, a2);
    sp1C = func_8008C3C4();
    return sp1C;
}
