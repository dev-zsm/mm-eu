// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_map_exp.h"

void Map_Update(PlayState* play) {
    InterfaceContext* interfaceCtx = &play->interfaceCtx;
    Player* player = GET_PLAYER(play);
    Input* controller = CONTROLLER1(&play->state);
    s32 pad1;
    s16 floor;
    s32 pad2;

    if ((play->pauseCtx.state <= PAUSE_STATE_OPENING_2) && (CHECK_BTN_ALL(controller->press.button, BTN_L)) &&
        !Play_InCsMode(play) && !MapDisp_IsMinimapToggleBlocked(play)) {
        if (!R_MINIMAP_DISABLED) {
            Audio_PlaySfx(NA_SE_SY_CAMERA_ZOOM_UP);
        } else {
            Audio_PlaySfx(NA_SE_SY_CAMERA_ZOOM_DOWN);
        }

        R_MINIMAP_DISABLED ^= 1;
    }

    MapDisp_Update(play);

    if (!IS_PAUSED(&play->pauseCtx)) {
        if (Map_IsInDungeonScene(play)) {
            floor = MapDisp_GetPlayerStorey(player->actor.world.pos.y);
            if (floor != -1) {
                SET_DUNGEON_FLOOR_VISITED(Play_GetOriginalSceneId(play->sceneId), FLOOR_INDEX_MAX - floor);
                R_PLAYER_FLOOR_REVERSE_INDEX = FLOOR_INDEX_MAX - floor;
                if (interfaceCtx->mapRoomNum != sLastRoomNum) {
                    sLastRoomNum = interfaceCtx->mapRoomNum;
                }
            }
        } else if (Map_IsInBossScene(play)) {
            MapDisp_GetBossIconY();
            R_PLAYER_FLOOR_REVERSE_INDEX = FLOOR_INDEX_MAX - MapDisp_GetBossRoomStorey();
        }
    }
}
