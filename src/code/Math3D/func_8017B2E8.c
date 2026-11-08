// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

s32 Math3D_PointInSquare2D(f32 upperLeftX, f32 lowerRightX, f32 upperLeftY, f32 lowerRightY, f32 x, f32 y) {
    if ((upperLeftX <= x) && (x <= lowerRightX) && (upperLeftY <= y) && (y <= lowerRightY)) {
        return 1;
    }
    return 0;
}
