// FLAGS: -O2 -g3 -mips2
#include "types.h"
extern s32 func_80173B14(s32 a0, s32 a1, s32 a2);
s32 THGA_AllocMtxArray(s32 a0, s32 a1) {
    return func_80173B14(a0, a1 << 6, a1);
}
