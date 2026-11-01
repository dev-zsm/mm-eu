// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 Cutscene_GetSceneLayer();                                /* extern */
extern s32 D_801E6EF0;

s32 MapDisp_IsLocationRomaniRanchAltScene(void) {
    if ((D_801E6EF0 == 0x6400) && (Cutscene_GetSceneLayer() != 0)) {
        return 1;
    }
    return 0;
}
