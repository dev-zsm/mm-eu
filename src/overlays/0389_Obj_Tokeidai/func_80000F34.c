// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_tokeidai.h"

void ObjTokeidai_TowerOpening_EndCutscene(ObjTokeidai* this, PlayState* play) {
    if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_132) &&
        (play->csCtx.actorCues[Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_132)]->id == 5)) {
        SET_WEEKEVENTREG(WEEKEVENTREG_CLOCK_TOWER_OPENED);
        if (((play->sceneId == SCENE_CLOCKTOWER) && (gSaveContext.sceneLayer == 2) && (play->csCtx.scriptIndex == 0)) ||
            ((play->sceneId == SCENE_00KEIKOKU) && (gSaveContext.sceneLayer == 2) && (play->csCtx.scriptIndex == 0))) {
            Audio_SetCutsceneFlag(false);
            gSaveContext.save.cutsceneIndex = 0;
            gSaveContext.nextCutsceneIndex = 0;
            gSaveContext.respawnFlag = 2;
            play->transitionTrigger = TRANS_TRIGGER_START;
            play->nextEntrance = gSaveContext.respawn[RESPAWN_MODE_RETURN].entrance;
            play->transitionType = TRANS_TYPE_FADE_BLACK;
            if (gSaveContext.respawn[RESPAWN_MODE_RETURN].playerParams ==
                PLAYER_PARAMS(0xFF, PLAYER_START_MODE_TELESCOPE)) {
                gSaveContext.nextTransitionType = TRANS_TYPE_CIRCLE;
            } else {
                gSaveContext.nextTransitionType = TRANS_TYPE_FADE_BLACK;
            }
        }
        this->actionFunc = ObjTokeidai_DoNothing;
    }
}
