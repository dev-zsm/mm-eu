// FLAGS: -g
// COMPILER: ido53
#include "types.h"

extern s32 D_801F4938;

s32 func_80187910(s32 value) {
    s32 result;

    if (D_801F4938 == 0) {
        result = value << 6;
    } else {
        result = value << 7;
    }
    return result;
}
