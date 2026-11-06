// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test7.h"

void EnTest7_WarpCsWarp(EnTest7* this, PlayState* play) {
    Vec3f featherPos;

    
    if (1) {}

    Math_Vec3f_Copy(&featherPos, &this->actor.world.pos);

    if (Rand_ZeroOne() < 0.1f) {
        EnTest7_AddAndChooseFeather(this->feathers, &featherPos, true);
    }

    this->windCapsule.yaw -= 0x2EE0;

    if (play->sceneId == SCENE_SECOM) {
        play->nextEntrance = ENTRANCE(IKANA_CANYON, 6);
    } else if (OWL_WARP_CS_GET_OCARINA_MODE(&this->actor) == OCARINA_MODE_WARP_TO_ENTRANCE) {
        ref_func_80169F78(play);
        gSaveContext.respawn[RESPAWN_MODE_TOP].playerParams =
            PLAYER_PARAMS(gSaveContext.respawn[RESPAWN_MODE_TOP].playerParams, PLAYER_START_MODE_OWL);
        gSaveContext.respawnFlag = -6;
    } else {
        play->nextEntrance =
            sOwlWarpEntrances[OWL_WARP_CS_GET_OCARINA_MODE(&this->actor) - OCARINA_MODE_WARP_TO_GREAT_BAY_COAST];
        if ((play->nextEntrance == ENTRANCE(SOUTHERN_SWAMP_POISONED, 10)) &&
            CHECK_WEEKEVENTREG(WEEKEVENTREG_CLEARED_WOODFALL_TEMPLE)) {
            play->nextEntrance = ENTRANCE(SOUTHERN_SWAMP_CLEARED, 10);
        } else if ((play->nextEntrance == ENTRANCE(MOUNTAIN_VILLAGE_WINTER, 8)) &&
                   CHECK_WEEKEVENTREG(WEEKEVENTREG_CLEARED_SNOWHEAD_TEMPLE)) {
            play->nextEntrance = ENTRANCE(MOUNTAIN_VILLAGE_SPRING, 8);
        }
    }

    play->transitionTrigger = TRANS_TRIGGER_START;
    play->transitionType = TRANS_TYPE_FADE_BLACK;
    gSaveContext.seqId = (u8)NA_BGM_DISABLED;
    gSaveContext.ambienceId = AMBIENCE_ID_DISABLED;
}
