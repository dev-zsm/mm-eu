#include "types.h"

extern s32 D_80AD0CA0;

// only the bnel operand order differs (ROM: t6,a1)
s32 func_8000012C(s32 a, s32 b) {
    if (a == 0) {
        if (D_80AD0CA0 == b) {
            return 1;
        }
    } else if (a == 1) {
        D_80AD0CA0 = b;
        return 1;
    }
    return 0;
}
