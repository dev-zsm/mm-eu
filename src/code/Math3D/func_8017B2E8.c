// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 Math3D_PointInSquare2D(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    if ((arg0 <= arg4) && (arg4 <= arg1) && (arg2 <= arg5) && (arg5 <= arg3)) {
        return 1;
    }
    return 0;
}
