// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

extern s32 D_801EAB9C;

s32 Cutscene_GetSceneLayer(struct PlayState *play) {
    s32 var_v1;

    var_v1 = 0;
    if (D_801EAB9C > 0) {
        var_v1 = D_801EAB9C;
    }
    return var_v1;
}
