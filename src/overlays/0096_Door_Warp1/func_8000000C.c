// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_warp1.h"

s32 DoorWarp1_GetRemains(DoorWarp1* this, PlayState* play) {
    s32 remains = DOORWARP1_REMAINS_NONE;

    if ((play->sceneId == SCENE_MITURIN_BS) && !CHECK_QUEST_ITEM(QUEST_REMAINS_ODOLWA)) {
        remains = DOORWARP1_REMAINS_ODOLWA;
    } else if ((play->sceneId == SCENE_HAKUGIN_BS) && !CHECK_QUEST_ITEM(QUEST_REMAINS_GOHT)) {
        remains = DOORWARP1_REMAINS_GOHT;
    } else if ((play->sceneId == SCENE_SEA_BS) && !CHECK_QUEST_ITEM(QUEST_REMAINS_GYORG)) {
        remains = DOORWARP1_REMAINS_GYORG;
    } else if ((play->sceneId == SCENE_INISIE_BS) && !CHECK_QUEST_ITEM(QUEST_REMAINS_TWINMOLD)) {
        remains = DOORWARP1_REMAINS_TWINMOLD;
    }
    return remains;
}
