// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_play.h"

void Play_UpdateTransition(PlayState* this) {
    s32 pad;

    if (this->transitionMode == TRANS_MODE_OFF) {
        return;
    }

    switch (this->transitionMode) {
        case TRANS_MODE_SETUP:
            if (this->transitionTrigger != TRANS_TRIGGER_END) {
                s16 sceneLayer = 0;

                Interface_SetHudVisibility(HUD_VISIBILITY_NONE);

                if (gSaveContext.nextCutsceneIndex >= 0xFFF0) {
                    sceneLayer = (gSaveContext.nextCutsceneIndex & 0xF) + 1;
                }

                if ((!(Entrance_GetTransitionFlags(this->nextEntrance + sceneLayer) & 0x8000) ||
                     ((this->nextEntrance == ENTRANCE(PATH_TO_MOUNTAIN_VILLAGE, 1)) &&
                      !CHECK_WEEKEVENTREG(WEEKEVENTREG_CLEARED_SNOWHEAD_TEMPLE)) ||
                     ((this->nextEntrance == ENTRANCE(ROAD_TO_SOUTHERN_SWAMP, 1)) &&
                      !CHECK_WEEKEVENTREG(WEEKEVENTREG_CLEARED_WOODFALL_TEMPLE)) ||
                     ((this->nextEntrance == ENTRANCE(TERMINA_FIELD, 2)) &&
                      !CHECK_WEEKEVENTREG(WEEKEVENTREG_CLEARED_GREAT_BAY_TEMPLE)) ||
                     ((this->nextEntrance == ENTRANCE(ROAD_TO_IKANA, 1)) &&
                      !CHECK_WEEKEVENTREG(WEEKEVENTREG_CLEARED_STONE_TOWER_TEMPLE))) &&
                    (!Environment_IsFinalHours(this) || (Entrance_GetSceneId(this->nextEntrance + sceneLayer) < 0) ||
                     (AudioSeq_GetActiveSeqId(SEQ_PLAYER_BGM_MAIN) != NA_BGM_FINAL_HOURS))) {
                    Audio_MuteAllSeqExceptSystemAndOcarina(20);
                    gSaveContext.seqId = (u8)NA_BGM_DISABLED;
                    gSaveContext.ambienceId = AMBIENCE_ID_DISABLED;
                }

                if (Environment_IsForcedSequenceDisabled()) {
                    Audio_MuteAllSeqExceptSystemAndOcarina(20);
                    gSaveContext.seqId = (u8)NA_BGM_DISABLED;
                    gSaveContext.ambienceId = AMBIENCE_ID_DISABLED;
                }

                if (Environment_IsFinalHours(this) && (Entrance_GetSceneId(this->nextEntrance + sceneLayer) >= 0) &&
                    (AudioSeq_GetActiveSeqId(SEQ_PLAYER_BGM_MAIN) == NA_BGM_FINAL_HOURS)) {
                    Audio_MuteSfxAndAmbienceSeqExceptSysAndOca(20);
                }
            }

            if (!ref_D_801D0D54) {
                Play_SetupTransition(this, Play_ChooseDynamicTransition(this, this->transitionType));
            }

            if (this->transitionMode >= TRANS_MODE_FILL_WHITE_INIT) {
                
                break;
            }
            FALLTHROUGH;
        case TRANS_MODE_INSTANCE_INIT: {
            s32 transWipeSpeed;
            s32 transFadeDuration;
            u32 color;

            this->transitionCtx.init(&this->transitionCtx.instanceData);

            if (this->transitionCtx.transitionType & (TRANS_TYPE_WIPE3 | TRANS_TYPE_WIPE4)) {
                this->transitionCtx.setType(&this->transitionCtx.instanceData,
                                            this->transitionCtx.transitionType | TRANS_TYPE_SET_PARAMS);
            }

            if ((this->transitionCtx.transitionType == TRANS_TYPE_WIPE_FAST) ||
                (this->transitionCtx.transitionType == TRANS_TYPE_FILL_WHITE_FAST)) {
                
                
                transWipeSpeed = 28;
            } else {
                transWipeSpeed = 14;
            }
            gSaveContext.transWipeSpeed = transWipeSpeed;

            switch (this->transitionCtx.transitionType) {
                case TRANS_TYPE_FADE_BLACK_FAST:
                case TRANS_TYPE_FADE_WHITE_FAST:
                    transFadeDuration = 20;
                    break;

                case TRANS_TYPE_FADE_BLACK_SLOW:
                case TRANS_TYPE_FADE_WHITE_SLOW:
                    transFadeDuration = 150;
                    break;

                case TRANS_TYPE_FADE_WHITE_INSTANT:
                    transFadeDuration = 2;
                    break;

                default:
                    transFadeDuration = 60;
                    break;
            }
            gSaveContext.transFadeDuration = transFadeDuration;

            switch (this->transitionCtx.transitionType) {
                case TRANS_TYPE_FADE_WHITE:
                case TRANS_TYPE_FADE_WHITE_FAST:
                case TRANS_TYPE_FADE_WHITE_SLOW:
                case TRANS_TYPE_FADE_WHITE_CS_DELAYED:
                case TRANS_TYPE_FADE_WHITE_INSTANT:
                    color = RGBA8(160, 160, 160, 255);
                    break;

                case TRANS_TYPE_FADE_GREEN:
                    color = RGBA8(140, 140, 100, 255);
                    break;

                case TRANS_TYPE_FADE_BLUE:
                    color = RGBA8(70, 100, 110, 255);
                    break;

                default:
                    color = RGBA8(0, 0, 0, 255);
                    break;
            }

            this->transitionCtx.setColor(&this->transitionCtx.instanceData, color);
            if (this->transitionCtx.setEnvColor != NULL) {
                this->transitionCtx.setEnvColor(&this->transitionCtx.instanceData, color);
            }

            this->transitionCtx.setType(&this->transitionCtx.instanceData,
                                        (this->transitionTrigger == TRANS_TRIGGER_END) ? TRANS_INSTANCE_TYPE_FILL_OUT
                                                                                       : TRANS_INSTANCE_TYPE_FILL_IN);
            this->transitionCtx.start(&this->transitionCtx.instanceData);

            if (this->transitionCtx.transitionType == TRANS_TYPE_FADE_WHITE_CS_DELAYED) {
                this->transitionMode = TRANS_MODE_INSTANCE_WAIT;
            } else {
                this->transitionMode = TRANS_MODE_INSTANCE_RUNNING;
            }
            break;
        }

        case TRANS_MODE_INSTANCE_RUNNING:
            if (this->transitionCtx.isDone(&this->transitionCtx.instanceData)) {
                if (this->transitionTrigger != TRANS_TRIGGER_END) {
                    if (this->transitionCtx.transitionType == TRANS_TYPE_CIRCLE) {
                        ref_D_801D0D54 = false;
                    }

                    if (gSaveContext.gameMode == GAMEMODE_OWL_SAVE) {
                        STOP_GAMESTATE(&this->state);
                        SET_NEXT_GAMESTATE(&this->state, TitleSetup_Init, sizeof(TitleSetupState));
                    } else if (gSaveContext.gameMode != GAMEMODE_FILE_SELECT) {
                        STOP_GAMESTATE(&this->state);
                        SET_NEXT_GAMESTATE(&this->state, Play_Init, sizeof(PlayState));
                        gSaveContext.save.entrance = this->nextEntrance;

                        if (gSaveContext.minigameStatus == MINIGAME_STATUS_ACTIVE) {
                            gSaveContext.minigameStatus = MINIGAME_STATUS_END;
                        }
                    } else { 
                        STOP_GAMESTATE(&this->state);
                        SET_NEXT_GAMESTATE(&this->state, FileSelect_Init, sizeof(FileSelectState));
                    }
                } else {
                    if (this->transitionCtx.transitionType == TRANS_TYPE_CIRCLE) {
                        ref_D_801D0D54 = true;
                    } else {
                        this->transitionCtx.destroy(&this->transitionCtx.instanceData);
                        Play_ClearTransition(this);
                    }
                    this->transitionMode = TRANS_MODE_OFF;
                    if (gTransitionTileState == TRANS_TILE_READY) {
                        TransitionTile_Destroy(&sTransitionTile);
                        gTransitionTileState = TRANS_TILE_OFF;
                        GameState_SetFramerateDivisor(&this->state, 3);
                    }
                }
                this->transitionTrigger = TRANS_TRIGGER_OFF;
            } else {
                this->transitionCtx.update(&this->transitionCtx.instanceData, this->state.framerateDivisor);
            }
            break;
    }

    
    switch (this->transitionMode) {
        case TRANS_MODE_FILL_WHITE_INIT:
            sTransitionFillTimer = 0;
            this->envCtx.fillScreen = true;
            this->envCtx.screenFillColor[0] = 160;
            this->envCtx.screenFillColor[1] = 160;
            this->envCtx.screenFillColor[2] = 160;

            if (this->transitionTrigger != TRANS_TRIGGER_END) {
                this->envCtx.screenFillColor[3] = 0;
                this->transitionMode = TRANS_MODE_FILL_IN;
            } else {
                this->envCtx.screenFillColor[3] = 255;
                this->transitionMode = TRANS_MODE_FILL_OUT;
            }
            break;

        case TRANS_MODE_FILL_IN:
            this->envCtx.screenFillColor[3] = (sTransitionFillTimer / 20.0f) * 255.0f;

            if (sTransitionFillTimer >= 20) {
                STOP_GAMESTATE(&this->state);
                SET_NEXT_GAMESTATE(&this->state, Play_Init, sizeof(PlayState));
                gSaveContext.save.entrance = this->nextEntrance;
                this->transitionTrigger = TRANS_TRIGGER_OFF;
                this->transitionMode = TRANS_MODE_OFF;
            } else {
                sTransitionFillTimer++;
            }
            break;

        case TRANS_MODE_FILL_OUT:
            this->envCtx.screenFillColor[3] = (1.0f - (sTransitionFillTimer / 20.0f)) * 255.0f;

            if (sTransitionFillTimer >= 20) {
                gTransitionTileState = TRANS_TILE_OFF;
                GameState_SetFramerateDivisor(&this->state, 3);
                this->transitionTrigger = TRANS_TRIGGER_OFF;
                this->transitionMode = TRANS_MODE_OFF;
                this->envCtx.fillScreen = false;
            } else {
                sTransitionFillTimer++;
            }
            break;

        case TRANS_MODE_FILL_BROWN_INIT:
            sTransitionFillTimer = 0;
            this->envCtx.fillScreen = true;
            this->envCtx.screenFillColor[0] = 170;
            this->envCtx.screenFillColor[1] = 160;
            this->envCtx.screenFillColor[2] = 150;

            if (this->transitionTrigger != TRANS_TRIGGER_END) {
                this->envCtx.screenFillColor[3] = 0;
                this->transitionMode = TRANS_MODE_FILL_IN;
            } else {
                this->envCtx.screenFillColor[3] = 255;
                this->transitionMode = TRANS_MODE_FILL_OUT;
            }
            break;

        case TRANS_MODE_INSTANT:
            if (this->transitionTrigger != TRANS_TRIGGER_END) {
                STOP_GAMESTATE(&this->state);
                SET_NEXT_GAMESTATE(&this->state, Play_Init, sizeof(PlayState));
                gSaveContext.save.entrance = this->nextEntrance;
                this->transitionTrigger = TRANS_TRIGGER_OFF;
                this->transitionMode = TRANS_MODE_OFF;
            } else {
                gTransitionTileState = TRANS_TILE_OFF;
                GameState_SetFramerateDivisor(&this->state, 3);
                this->transitionTrigger = TRANS_TRIGGER_OFF;
                this->transitionMode = TRANS_MODE_OFF;
            }
            break;

        case TRANS_MODE_INSTANCE_WAIT:
            if (gSaveContext.cutsceneTransitionControl != 0) {
                this->transitionMode = TRANS_MODE_INSTANCE_RUNNING;
            }
            break;

        case TRANS_MODE_SANDSTORM_INIT:
            if (this->transitionTrigger != TRANS_TRIGGER_END) {
                this->envCtx.sandstormState = SANDSTORM_FILL;
                this->transitionMode = TRANS_MODE_SANDSTORM;
            } else {
                this->envCtx.sandstormState = SANDSTORM_UNFILL;
                this->envCtx.sandstormPrimA = 255;
                this->envCtx.sandstormEnvA = 255;
                this->transitionMode = TRANS_MODE_SANDSTORM;
            }
            break;

        case TRANS_MODE_SANDSTORM:
            Audio_PlaySfx_2(NA_SE_EV_SAND_STORM - SFX_FLAG);
            if (this->transitionTrigger == TRANS_TRIGGER_END) {
                if (this->envCtx.sandstormPrimA < 110) {
                    gTransitionTileState = TRANS_TILE_OFF;
                    GameState_SetFramerateDivisor(&this->state, 3);
                    this->transitionTrigger = TRANS_TRIGGER_OFF;
                    this->transitionMode = TRANS_MODE_OFF;
                }
            } else {
                if (this->envCtx.sandstormEnvA == 255) {
                    STOP_GAMESTATE(&this->state);
                    SET_NEXT_GAMESTATE(&this->state, Play_Init, sizeof(PlayState));
                    gSaveContext.save.entrance = this->nextEntrance;
                    this->transitionTrigger = TRANS_TRIGGER_OFF;
                    this->transitionMode = TRANS_MODE_OFF;
                }
            }
            break;

        case TRANS_MODE_SANDSTORM_END_INIT:
            if (this->transitionTrigger == TRANS_TRIGGER_END) {
                this->envCtx.sandstormState = SANDSTORM_DISSIPATE;
                this->envCtx.sandstormPrimA = 255;
                this->envCtx.sandstormEnvA = 255;

                (void)T("来た!!!!!!!!!!!!!!!!!!!!!", "It's here!!!!!!!!!!!!!!!!!!!!!");

                this->transitionMode = TRANS_MODE_SANDSTORM_END;
            } else {
                this->transitionMode = TRANS_MODE_SANDSTORM_INIT;
            }
            break;

        case TRANS_MODE_SANDSTORM_END:
            Audio_PlaySfx_2(NA_SE_EV_SAND_STORM - SFX_FLAG);

            if (this->transitionTrigger == TRANS_TRIGGER_END) {
                if (this->envCtx.sandstormPrimA <= 0) {
                    gTransitionTileState = TRANS_TILE_OFF;
                    GameState_SetFramerateDivisor(&this->state, 3);
                    this->transitionTrigger = TRANS_TRIGGER_OFF;
                    this->transitionMode = TRANS_MODE_OFF;
                }
            }
            break;

        case TRANS_MODE_CS_BLACK_FILL_INIT:
            sTransitionFillTimer = 0;
            this->envCtx.fillScreen = true;
            this->envCtx.screenFillColor[0] = 0;
            this->envCtx.screenFillColor[1] = 0;
            this->envCtx.screenFillColor[2] = 0;
            this->envCtx.screenFillColor[3] = 255;
            this->transitionMode = TRANS_MODE_CS_BLACK_FILL;
            break;

        case TRANS_MODE_CS_BLACK_FILL:
            if (gSaveContext.cutsceneTransitionControl != 0) {
                this->envCtx.screenFillColor[3] = gSaveContext.cutsceneTransitionControl;

                if (gSaveContext.cutsceneTransitionControl <= 100) {
                    gTransitionTileState = TRANS_TILE_OFF;
                    GameState_SetFramerateDivisor(&this->state, 3);
                    this->transitionTrigger = TRANS_TRIGGER_OFF;
                    this->transitionMode = TRANS_MODE_OFF;
                }
            }
            break;
    }
}
