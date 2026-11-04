// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_game_over.h"

void GameOver_Update(PlayState* play) {
    GameOverContext* gameOverCtx = &play->gameOverCtx;
    s16 timerId;

    switch (gameOverCtx->state) {
        case GAMEOVER_DEATH_START:
            Message_CloseTextbox(play);

            for (timerId = 0; timerId < TIMER_ID_MAX; timerId++) {
                gSaveContext.timerStates[timerId] = TIMER_STATE_OFF;
            }

            CLEAR_EVENTINF_ALT(EVENTINF_10);

            if (CUR_FORM == 0) {
                if (CUR_FORM_EQUIP(EQUIP_SLOT_B) != ITEM_SWORD_KOKIRI &&
                    CUR_FORM_EQUIP(EQUIP_SLOT_B) != ITEM_SWORD_RAZOR &&
                    CUR_FORM_EQUIP(EQUIP_SLOT_B) != ITEM_SWORD_GILDED &&
                    CUR_FORM_EQUIP(EQUIP_SLOT_B) != ITEM_SWORD_DEITY) {

                    if (gSaveContext.buttonStatus[EQUIP_SLOT_B] != BTN_ENABLED) {
                        CUR_FORM_EQUIP(EQUIP_SLOT_B) = gSaveContext.buttonStatus[EQUIP_SLOT_B];
                    } else {
                        CUR_FORM_EQUIP(EQUIP_SLOT_B) = ITEM_NONE;
                    }
                }
            }

            gSaveContext.nayrusLoveTimer = 2000;
            gSaveContext.save.saveInfo.playerData.tatlTimer = 0;
            gSaveContext.seqId = (u8)NA_BGM_DISABLED;
            gSaveContext.ambienceId = AMBIENCE_ID_DISABLED;
            gSaveContext.eventInf[0] = 0;
            gSaveContext.eventInf[1] = 0;
            gSaveContext.eventInf[2] = 0;
            gSaveContext.eventInf[3] = 0;
            gSaveContext.buttonStatus[EQUIP_SLOT_B] = BTN_ENABLED;
            gSaveContext.buttonStatus[EQUIP_SLOT_C_LEFT] = BTN_ENABLED;
            gSaveContext.buttonStatus[EQUIP_SLOT_C_DOWN] = BTN_ENABLED;
            gSaveContext.buttonStatus[EQUIP_SLOT_C_RIGHT] = BTN_ENABLED;
            gSaveContext.buttonStatus[EQUIP_SLOT_A] = BTN_ENABLED;
            gSaveContext.hudVisibilityForceButtonAlphasByStatus = false;
            gSaveContext.nextHudVisibility = HUD_VISIBILITY_IDLE;
            gSaveContext.hudVisibility = HUD_VISIBILITY_IDLE;
            gSaveContext.hudVisibilityTimer = 0;
            Environment_InitGameOverLights(play);
            sGameOverTimer = 20;
            Rumble_Request(0.0f, 126, 124, 63);
            gameOverCtx->state = GAMEOVER_DEATH_WAIT_GROUND;
            break;

        case GAMEOVER_DEATH_FADE_OUT:
            if (AudioSeq_GetActiveSeqId(SEQ_PLAYER_FANFARE) != NA_BGM_GAME_OVER) {
                ref_func_80169F78(play);
                if (gSaveContext.respawnFlag != -7) {
                    gSaveContext.respawnFlag = -6;
                }
                gSaveContext.nextTransitionType = TRANS_TYPE_FADE_BLACK;
                gSaveContext.save.saveInfo.playerData.health = 0x30;
                gameOverCtx->state++;
                if (INV_CONTENT(ITEM_MASK_DEKU) == ITEM_MASK_DEKU) {
                    gSaveContext.save.playerForm = PLAYER_FORM_HUMAN;
                    gSaveContext.save.equippedMask = PLAYER_MASK_NONE;
                }
                Rumble_StateReset();
            }
            break;

        case GAMEOVER_REVIVE_START:
            gameOverCtx->state++; 
            sGameOverTimer = 0;
            Environment_InitGameOverLights(play);
            ShrinkWindow_Letterbox_SetSizeTarget(32);
            break;

        case GAMEOVER_REVIVE_RUMBLE:
            sGameOverTimer = 50;
            gameOverCtx->state++; 
            Rumble_Request(0.0f, 126, 124, 63);
            break;

        case GAMEOVER_REVIVE_WAIT_GROUND:
            sGameOverTimer--;
            if (sGameOverTimer == 0) {
                sGameOverTimer = 64;
                gameOverCtx->state++; 
            }
            break;

        case GAMEOVER_REVIVE_WAIT_FAIRY:
            sGameOverTimer--;
            if (sGameOverTimer == 0) {
                sGameOverTimer = 50;
                gameOverCtx->state++; 
            }
            break;

        case GAMEOVER_REVIVE_FADE_OUT:
            Environment_FadeOutGameOverLights(play);
            sGameOverTimer--;
            if (sGameOverTimer == 0) {
                gameOverCtx->state = GAMEOVER_INACTIVE;
            }
            break;
    }
}
