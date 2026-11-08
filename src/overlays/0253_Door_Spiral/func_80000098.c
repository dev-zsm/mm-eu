// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_spiral.h"

u8 ref_func_809A2BF8(PlayState* play) {
    SpiralSceneInfo* spiralSceneInfo = sSpiralSceneInfoTable;
    s32 i;
    u8 var_v1;

    for (i = 0; i < ARRAY_COUNT(sSpiralSceneInfoTable); i++) {
        if (play->sceneId == spiralSceneInfo->sceneId) {
            break;
        }
        spiralSceneInfo++;
    }
    if (i < ARRAY_COUNT(sSpiralSceneInfoTable)) {
        var_v1 = spiralSceneInfo->index;
    } else {
        var_v1 = (Object_GetSlot(&play->objectCtx, GAMEPLAY_DANGEON_KEEP) > OBJECT_SLOT_NONE) ? 1 : 0;
    }
    return var_v1;
}
