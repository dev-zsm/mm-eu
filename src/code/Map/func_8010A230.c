// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_map_exp.h"

void Map_Init(PlayState* play) {
    InterfaceContext* interfaceCtx = &play->interfaceCtx;
    s32 dungeonSceneSharedIndex;

    MapDisp_SwapRooms(play->roomCtx.curRoom.num);
    interfaceCtx->unk_278 = -1;
    interfaceCtx->dungeonSceneIndex = -1;
    interfaceCtx->mapSegment = THA_AllocTailAlign16(&play->state.tha, 0x1000);

    
    
    if (Map_IsInOverworldSceneWithMapIndex(play)) {
        gSaveContext.mapIndex = Map_GetMapIndexForOverworld(play);
        return;
    }

    if (Map_IsInDungeonOrBossScene(play)) {
        gSaveContext.mapIndex = dungeonSceneSharedIndex = Map_GetDungeonSceneIndex(play);
        switch (play->sceneId) {
            case SCENE_MITURIN_BS:
                dungeonSceneSharedIndex = DUNGEON_SCENE_INDEX_WOODFALL_TEMPLE;
                break;

            case SCENE_HAKUGIN_BS:
                dungeonSceneSharedIndex = DUNGEON_SCENE_INDEX_SNOWHEAD_TEMPLE;
                break;

            case SCENE_SEA_BS:
                dungeonSceneSharedIndex = DUNGEON_SCENE_INDEX_GREAT_BAY_TEMPLE;
                break;

            case SCENE_INISIE_BS:
                dungeonSceneSharedIndex = DUNGEON_SCENE_INDEX_STONE_TOWER_TEMPLE;
                break;
        }

        gSaveContext.dungeonSceneSharedIndex = dungeonSceneSharedIndex;
        Map_InitRoomData(play, play->roomCtx.curRoom.num);
    }
}
