// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

extern void *D_80096D80;
void func_800845C8(void);
void func_8008E1F0(void *fn, void *a1, s32 a2, s32 a3);

void func_800847DC(s32 a0, s32 a1) {
    func_8008E1F0(func_800845C8, D_80096D80, a0, a1);
}
