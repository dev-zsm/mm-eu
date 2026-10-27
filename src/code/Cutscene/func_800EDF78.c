// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern s32 D_801EAB9C;

s32 Cutscene_GetSceneLayer(s32 arg0) {
    s32 var_v1;

    var_v1 = 0;
    if (D_801EAB9C > 0) {
        var_v1 = D_801EAB9C;
    }
    return var_v1;
}
