// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_warp_tag.h"

void EnWarpTag_RespawnPlayer(EnWarptag* this, PlayState* play) {
    ActorEntry* playerActorEntry;
    Player* player = GET_PLAYER(play);
    s32 playerSpawnIndex;
    s32 new15E;
    s32 entrance;
    u32 playerSpawnIndexPerForm[PLAYER_FORM_MAX];
    u8 playerForm;
    s16 playerParams;

    if ((play->playerCsIds[PLAYER_CS_ID_WARP_PAD_MOON] >= 0) &&
        (CutsceneManager_GetCurrentCsId() != play->playerCsIds[PLAYER_CS_ID_WARP_PAD_MOON])) {
        if (!CutsceneManager_IsNext(play->playerCsIds[PLAYER_CS_ID_WARP_PAD_MOON])) {
            CutsceneManager_Queue(play->playerCsIds[PLAYER_CS_ID_WARP_PAD_MOON]);

        } else {
            CutsceneManager_StartWithPlayerCs(play->playerCsIds[PLAYER_CS_ID_WARP_PAD_MOON], &this->dyna.actor);
            Player_PlaySfx(player, NA_SE_PL_WARP_PLATE);
            Play_EnableMotionBlur(0);
        }

    } else {
        f32 diffX = player->actor.world.pos.x - this->dyna.actor.world.pos.x;
        Vec3f newRespawnPos;
        f32 diffZ = player->actor.world.pos.z - this->dyna.actor.world.pos.z;
        f32 distance = sqrtf(SQ(diffX) + SQ(diffZ));

        
        if (distance != 0.0f) {
            distance = (distance - 1.0f) / distance;
            distance = CLAMP_MIN(distance, 0.0f);
        }

        player->actor.world.pos.x = this->dyna.actor.world.pos.x + (diffX * distance);
        player->actor.world.pos.z = this->dyna.actor.world.pos.z + (diffZ * distance);

        if (Math_StepToS(&this->unkValue15E, 0x2710, 0xC8)) {
            player->stateFlags3 |= PLAYER_STATE3_1;
            player->actor.gravity = -0.5f;

            if (this->dyna.actor.playerHeightRel < -80.0f) {
                playerSpawnIndexPerForm[PLAYER_FORM_FIERCE_DEITY] = WARPTAG_GET_EXIT_INDEX(&this->dyna.actor);
                playerSpawnIndexPerForm[PLAYER_FORM_HUMAN] = playerSpawnIndexPerForm[PLAYER_FORM_FIERCE_DEITY];
                playerSpawnIndexPerForm[PLAYER_FORM_GORON] = this->dyna.actor.world.rot.x;
                playerSpawnIndexPerForm[PLAYER_FORM_ZORA] = this->dyna.actor.world.rot.y;
                playerSpawnIndexPerForm[PLAYER_FORM_DEKU] = this->dyna.actor.world.rot.z;

                if (this->dyna.actor.draw != NULL) {
                    playerForm = PLAYER_BOOTS_FIERCE_DEITY;
                } else {
                    playerForm = player->transformation;
                }

                entrance = gSaveContext.save.entrance;

                playerSpawnIndex = playerSpawnIndexPerForm[playerForm];
                playerActorEntry = &play->linkActorEntry[playerSpawnIndex];
                newRespawnPos.x = playerActorEntry->pos.x;
                newRespawnPos.y = playerActorEntry->pos.y;
                newRespawnPos.z = playerActorEntry->pos.z;

                if (WARPTAG_GET_3C0_MAX(&this->dyna.actor) == WARPTAG_3C0_MAX) {
                    playerParams = PLAYER_PARAMS(0xFF, PLAYER_START_MODE_9);
                } else { 
                    playerParams = PLAYER_PARAMS(0xFF, PLAYER_START_MODE_8);
                }

                
                
                Play_SetRespawnData(play, RESPAWN_MODE_DOWN, entrance, play->setupEntranceList[playerSpawnIndex].room,
                                    playerParams, &newRespawnPos,
                                    DEG_TO_BINANG_ALT((playerActorEntry->rot.y >> 7) & 0x1FF));

                ref_func_80169EFC(play);
                gSaveContext.respawnFlag = -5;
                Play_DisableMotionBlur();
            }
        }

        player->actor.shape.rot.y += this->unkValue15E;
        new15E = this->unkValue15E - 0xFA0;
        if (new15E < 0) {
            new15E = 0;
        }
        Play_SetMotionBlurAlpha(new15E * (1 / 25.0f));
    }
}
