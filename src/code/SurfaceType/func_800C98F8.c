// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"
u32 SurfaceType_IsSoft(s32 a0, s32 a1, s32 a2) {
    return (SurfaceType_GetData(a0, a1, a2, 0) >> 30) & 1;
}
