// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern s32 D_801ED288;
extern s32 D_801ED2AC;
extern s32 D_801ED2D0;
extern s32 D_801ED2F4;

s32 Quake_GetNumActiveQuakes(void) {
    s32 var_v1;

    var_v1 = 0;
    if (D_801ED288 != 0) {
        var_v1 = 1;
    }
    if (D_801ED2AC != 0) {
        var_v1 += 1;
    }
    if (D_801ED2D0 != 0) {
        var_v1 += 1;
    }
    if (D_801ED2F4 != 0) {
        var_v1 += 1;
    }
    return var_v1;
}
