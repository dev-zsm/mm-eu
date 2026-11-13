// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnTest6_SharedSoTCutscene), score 4.00 (4 differ, size +2)
#include "generated/mm/z_en_test6.h"

void func_80002220(EnTest6* this, PlayState* play) {
    s32 pad[2];
    Player* player = GET_PLAYER(play);
    f32 yDiff;
    s32 i;
    s32 cueChannel;

    if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_SOTCS)) {
        cueChannel = Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_SOTCS);
        this->cueId = play->csCtx.actorCues[cueChannel]->id;

        switch (this->cueId) {
            case SOTCS_CUEID_DOUBLE_WAIT:
                break;

            case SOTCS_CUEID_DOUBLE_INIT:
                this->drawType = SOTCS_DRAW_DOUBLE_SOT;
                this->counter = 0;
                this->clockAngle = 0;
                player->actor.shape.shadowDraw = NULL;

                if (play->csCtx.actorCues[cueChannel]->startPos.x != 0) {
                    this->clockSpeed = (u32)play->csCtx.actorCues[cueChannel]->startPos.x;
                } else {
                    this->clockSpeed = 150.0f;
                }

                if (play->csCtx.actorCues[cueChannel]->startPos.y != 0) {
                    this->clockColorGray = play->csCtx.actorCues[cueChannel]->startPos.y;
                } else {
                    this->clockColorGray = 38;
                }

                if (play->csCtx.actorCues[cueChannel]->startPos.z != 0) {
                    this->clockDist = (u32)play->csCtx.actorCues[cueChannel]->startPos.z;
                } else {
                    this->clockDist = 480.0f;
                }
                break;

            case SOTCS_CUEID_DOUBLE_CLOCKS_INWARD:
                if (play->csCtx.actorCues[cueChannel]->startPos.x != 0) {
                    this->clockSpeed += (u32)play->csCtx.actorCues[cueChannel]->startPos.x;
                }

                if (play->csCtx.actorCues[cueChannel]->startPos.y != 0) {
                    this->clockColorGray += (s16)play->csCtx.actorCues[cueChannel]->startPos.y;

                } else {
                    this->clockColorGray += 6;
                }

                if (play->csCtx.actorCues[cueChannel]->startPos.z != 0) {
                    this->clockRadialSpeed = (u32)play->csCtx.actorCues[cueChannel]->startPos.z;
                } else {
                    this->clockRadialSpeed = -32.0f;
                }
                this->clockDist += this->clockRadialSpeed;
                break;

            case SOTCS_CUEID_DOUBLE_CLOCKS_SPIN:
                if (play->csCtx.actorCues[cueChannel]->startPos.x != 0) {
                    this->clockSpeed += (u32)play->csCtx.actorCues[cueChannel]->startPos.x;
                }

                if (play->csCtx.actorCues[cueChannel]->startPos.y != 0) {
                    this->clockColorGray += (s16)play->csCtx.actorCues[cueChannel]->startPos.y;
                } else {
                    this->clockColorGray -= 4;
                }
                break;

            case SOTCS_CUEID_DOUBLE_CLOCKS_OUTWARD:
                if (play->csCtx.actorCues[cueChannel]->startPos.x != 0) {
                    this->clockSpeed += (u32)play->csCtx.actorCues[cueChannel]->startPos.x;
                }

                if (play->csCtx.actorCues[cueChannel]->startPos.y != 0) {
                    this->clockColorGray += (s16)play->csCtx.actorCues[cueChannel]->startPos.y;
                } else {
                    this->clockColorGray -= 8;
                }

                if (play->csCtx.actorCues[cueChannel]->startPos.z != 0) {
                    this->clockRadialSpeed += (u32)play->csCtx.actorCues[cueChannel]->startPos.z;
                } else {
                    this->clockRadialSpeed += 20.0f;
                }

                this->clockDist += this->clockRadialSpeed;
                if (this->clockDist > 3500.0f) {
                    this->clockDist = 3500.0f;
                    this->cueId = SOTCS_CUEID_NONE;
                }
                break;

            case SOTCS_CUEID_RESET_INIT:
                this->drawType = SOTCS_DRAW_RESET_CYCLE_SOT;
                this->counter = 0;
                this->clockAngle = 0;
                player->actor.shape.shadowDraw = NULL;

                if (play->csCtx.actorCues[cueChannel]->startPos.x != 0) {
                    this->clockSpeed = (u32)play->csCtx.actorCues[cueChannel]->startPos.x;
                } else {
                    this->clockSpeed = 100.0f;
                }

                if (play->csCtx.actorCues[cueChannel]->startPos.y != 0) {
                    this->speed = (u32)play->csCtx.actorCues[cueChannel]->startPos.y;
                } else {
                    this->speed = 20.0f;
                }

                if (play->csCtx.actorCues[cueChannel]->startPos.z != 0) {
                    this->clockDist = (u32)play->csCtx.actorCues[cueChannel]->startPos.z;
                } else {
                    this->clockDist = 300.0f;
                }
                this->clockAccel = 0.0f;
                break;

            case SOTCS_CUEID_RESET_CLOCKS_SLOW_DOWN:
                if (play->csCtx.actorCues[cueChannel]->startPos.x != 0) {
                    this->clockAccel = (u32)play->csCtx.actorCues[cueChannel]->startPos.x;
                } else {
                    this->clockAccel = -5.0f;
                }
                this->clockSpeed += this->clockAccel;
                break;

            case SOTCS_CUEID_RESET_CLOCKS_SPEED_UP:
                if (play->csCtx.actorCues[cueChannel]->startPos.x != 0) {
                    this->clockAccel += (u32)play->csCtx.actorCues[cueChannel]->startPos.x;
                } else {
                    this->clockAccel += 2.0f;
                }

                this->clockSpeed += this->clockAccel;
                if (this->clockSpeed > 10000.0f) {
                    this->clockSpeed = 10000.0f;
                    this->cueId = SOTCS_CUEID_NONE;
                }
                break;

            case SOTCS_CUEID_NONE:
            default:
                this->drawType = SOTCS_DRAW_TYPE_NONE;
                return;

            case SOTCS_CUEID_DOUBLE_END:
                Play_SetRespawnData(play, RESPAWN_MODE_RETURN, ((void)0, gSaveContext.save.entrance), player->unk_3CE,
                                    PLAYER_PARAMS(0xFF, PLAYER_START_MODE_B), &player->unk_3C0, player->unk_3CC);
                this->drawType = SOTCS_DRAW_TYPE_NONE;
                play->transitionTrigger = TRANS_TRIGGER_START;
                play->nextEntrance = gSaveContext.respawn[RESPAWN_MODE_RETURN].entrance;
                play->transitionType = TRANS_TYPE_FADE_BLACK;
                if ((CURRENT_TIME > CLOCK_TIME(18, 0)) || (CURRENT_TIME < CLOCK_TIME(6, 0))) {
                    gSaveContext.respawnFlag = -0x63;
                    SET_EVENTINF(EVENTINF_TRIGGER_DAYTELOP);
                } else {
                    gSaveContext.respawnFlag = 2;
                }
                play->msgCtx.ocarinaMode = OCARINA_MODE_END;
                return;
        }
    } else {
        switch (this->cueId) {
            case SOTCS_CUEID_DOUBLE_INIT:
                this->drawType = SOTCS_DRAW_DOUBLE_SOT;
                this->counter = 0;
                this->clockAngle = 0;
                player->actor.shape.shadowDraw = NULL;
                this->clockColorGray = 38;
                this->clockSpeed = 150.0f;
                this->clockDist = 480.0f;
                break;

            case SOTCS_CUEID_DOUBLE_WAIT:
                break;

            case SOTCS_CUEID_DOUBLE_CLOCKS_INWARD:
                this->clockRadialSpeed = -32.0f;
                this->clockColorGray += 6;
                this->clockDist += -32.0f;
                break;

            case SOTCS_CUEID_DOUBLE_CLOCKS_SPIN:
                this->clockColorGray -= 4;
                break;

            case SOTCS_CUEID_DOUBLE_CLOCKS_OUTWARD:
                this->clockColorGray -= 8;
                this->clockRadialSpeed += 20.0f;
                this->clockDist += this->clockRadialSpeed;
                if (this->clockDist > 3500.0f) {
                    this->clockDist = 3500.0f;
                    this->cueId = SOTCS_CUEID_NONE;
                }
                break;

            case SOTCS_CUEID_RESET_INIT:
                this->drawType = SOTCS_DRAW_RESET_CYCLE_SOT;
                this->counter = 0;
                this->clockAngle = 0;
                player->actor.shape.shadowDraw = NULL;
                this->clockSpeed = 100.0f;
                this->speed = 20.0f;
                this->clockDist = 300.0f;
                this->clockAccel = 0.0f;
                break;

            case SOTCS_CUEID_RESET_CLOCKS_SLOW_DOWN:
                this->clockAccel = -5.0f;
                this->clockSpeed += -5.0f;
                break;

            case SOTCS_CUEID_RESET_CLOCKS_SPEED_UP:
                this->clockAccel += 2.0f;
                this->clockSpeed += this->clockAccel;
                if (this->clockSpeed > 10000.0f) {
                    this->clockSpeed = 10000.0f;
                    this->cueId = SOTCS_CUEID_NONE;
                }
                break;

            case SOTCS_CUEID_NONE:
            default:
                this->drawType = SOTCS_DRAW_TYPE_NONE;
                return;

            case SOTCS_CUEID_DOUBLE_END:
                if (CURRENT_TIME > CLOCK_TIME(12, 0)) {
                    Play_SetRespawnData(play, RESPAWN_MODE_RETURN, ((void)0, gSaveContext.save.entrance),
                                        player->unk_3CE, PLAYER_PARAMS(0xFF, PLAYER_START_MODE_B), &player->unk_3C0,
                                        player->unk_3CC);
                    this->drawType = SOTCS_DRAW_TYPE_NONE;
                    play->transitionTrigger = TRANS_TRIGGER_START;
                    play->nextEntrance = gSaveContext.respawn[RESPAWN_MODE_RETURN].entrance;
                    play->transitionType = TRANS_TYPE_FADE_BLACK;
                    gSaveContext.respawnFlag = 2;
                    play->msgCtx.ocarinaMode = OCARINA_MODE_END;
                }
                return;
        }
    }

    if (this->drawType == SOTCS_DRAW_RESET_CYCLE_SOT) {
        for (i = 0; i < ARRAY_COUNT(sSoTCsAmmoDrops); i++) {
            sSoTCsAmmoDrops[i].pos.x += 2.0f * ((2.0f * Rand_ZeroOne()) - 1.0f);
            sSoTCsAmmoDrops[i].pos.z += 2.0f * ((2.0f * Rand_ZeroOne()) - 1.0f);
            sSoTCsAmmoDrops[i].pos.y += 3.0f;

            if (player->actor.world.pos.y < sSoTCsAmmoDrops[i].pos.y) {
                yDiff = sSoTCsAmmoDrops[i].pos.y - player->actor.world.pos.y;
                if (yDiff > 550.0f) {
                    yDiff = 1.0f;
                } else {
                    yDiff /= 550.0f;
                }
                sSoTCsAmmoDrops[i].scale = SQ(yDiff);
            } else {
                sSoTCsAmmoDrops[i].scale = -10.0f;
            }
        }
    }
    this->counter++;
}
