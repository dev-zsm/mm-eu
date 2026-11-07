// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_ana.h"

void DoorAna_WaitOpen(DoorAna* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    s32 grottoType = DOORANA_GET_TYPE(&this->actor);

    if (Math_StepToF(&this->actor.scale.x, 0.01f, 0.001f)) {
        if ((this->actor.attentionRangeType != ATTENTION_RANGE_0) && (play->transitionTrigger == TRANS_TRIGGER_OFF) &&
            (play->transitionMode == TRANS_MODE_OFF) && (player->stateFlags1 & PLAYER_STATE1_80000000) &&
            (player->av1.actionVar1 == 0)) {

            if (grottoType == DOORANA_TYPE_VISIBLE_SCENE_EXIT) {
                s32 exitIndex = DOORANA_GET_EXIT_INDEX(&this->actor);

                play->nextEntrance = play->setupExitList[exitIndex];
            } else {
                s32 destinationIdx = DOORANA_GET_ENTRANCE(&this->actor);

                Play_SetupRespawnPoint(play, RESPAWN_MODE_UNK_3, PLAYER_PARAMS(0xFF, PLAYER_START_MODE_GROTTO));

                gSaveContext.respawn[RESPAWN_MODE_UNK_3].pos.y = this->actor.world.pos.y;
                gSaveContext.respawn[RESPAWN_MODE_UNK_3].yaw = this->actor.home.rot.y;

                
                gSaveContext.respawn[RESPAWN_MODE_UNK_3].data = DOORANA_GET_ITEMFLAGS(&this->actor);

                if (destinationIdx < 0) {
                    destinationIdx = DOORANA_GET_EX_ENTRANCE(&this->actor);
                }

                play->nextEntrance = sEntrances[destinationIdx];
            }

            DoorAna_SetupAction(this, DoorAna_GrabLink);

        } else if (!Play_InCsMode(play) && !(player->stateFlags1 & (PLAYER_STATE1_8000000 | PLAYER_STATE1_800000)) &&
                   (this->actor.xzDistToPlayer <= 20.0f) && (this->actor.playerHeightRel >= -50.0f) &&
                   (this->actor.playerHeightRel <= 15.0f)) {
            player->stateFlags1 |= PLAYER_STATE1_80000000;
            this->actor.attentionRangeType = ATTENTION_RANGE_1;

        } else {
            this->actor.attentionRangeType = ATTENTION_RANGE_0;
        }
    }

    Actor_SetScale(&this->actor, this->actor.scale.x);
}
