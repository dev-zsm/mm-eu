// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"
s32 SurfaceType_GetSceneExitIndex(s32 a0, s32 a1, s32 a2) {
    return (SurfaceType_GetData(a0, a1, a2, 0) >> 8) & 0x1F;
}
