// FLAGS: -O2 -g3 -mips2
#include "types.h"

void func_80173B14(s32, s32, s32);

void THGA_AllocVtxArray(s32 arg0, s32 arg1) {
    func_80173B14(arg0, arg1 << 4, arg1);
}
