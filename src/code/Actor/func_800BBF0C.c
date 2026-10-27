#include "types.h"
extern s32 D_801AF8E0[];
s32 Actor_GetArrowDmgFlags(s32 a0) {
    if (a0 < 0 || a0 >= 9) {
        return 0;
    }
    return D_801AF8E0[a0];
}
