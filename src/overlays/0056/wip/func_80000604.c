// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern s32 func_8082D728();
extern void func_800B8BDC();

void func_80000604(void *a0, s32 a1) {
    func_800B8BDC(a0, func_8082D728(a0, a1 & 0xFFFF) & 0xFFFF);
}
