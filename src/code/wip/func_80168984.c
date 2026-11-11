// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft, bytes match; links once `KaleidoSetup_Update` and the other symbols of the reference have names of ours
#include "generated/mm/z_play.h"

void Play_UpdateMain(PlayState* this) {
    s32 pad;
    Input* input = this->state.input;
    s32 sp5C = false;
    u8 freezeFlashTimer;

    gSegments[0x04] = OS_K0_TO_PHYSICAL(this->objectCtx.slots[this->objectCtx.mainKeepSlot].segment);
    gSegments[0x05] = OS_K0_TO_PHYSICAL(this->objectCtx.slots[this->objectCtx.subKeepSlot].segment);
    gSegments[0x02] = OS_K0_TO_PHYSICAL(this->sceneSegment);

    if (R_PICTO_PHOTO_STATE == PICTO_PHOTO_STATE_PROCESS) {
        R_PICTO_PHOTO_STATE = PICTO_PHOTO_STATE_READY;
        Sched_FlushTaskQueue();
        Play_TakePictoPhoto(&this->pauseBgPreRender);
        R_PICTO_PHOTO_STATE = PICTO_PHOTO_STATE_OFF;
    }

    Actor_SetMovementScale(this->state.framerateDivisor);

    if (FrameAdvance_Update(&this->frameAdvCtx, &input[1])) {
        if ((this->transitionMode == TRANS_MODE_OFF) && (this->transitionTrigger != TRANS_TRIGGER_OFF)) {
            this->transitionMode = TRANS_MODE_SETUP;
        }

        if (gTransitionTileState != TRANS_TILE_OFF) {
            switch (gTransitionTileState) {
                case TRANS_TILE_PROCESS:
                    if (TransitionTile_Init(&sTransitionTile, 10, 7) == NULL) {
                        gTransitionTileState = TRANS_TILE_OFF;
                    } else {
                        sTransitionTile.zBuffer = gZBufferPtr;
                        gTransitionTileState = TRANS_TILE_READY;
                        GameState_SetFramerateDivisor(&this->state, 1);
                    }
                    break;

                case TRANS_TILE_READY:
                    TransitionTile_Update(&sTransitionTile);
                    break;

                default:
                    break;
            }
        }

        Play_UpdateTransition(this);

        if (gTransitionTileState != TRANS_TILE_READY) {
            if ((gSaveContext.gameMode == GAMEMODE_NORMAL) &&
                ((((*(u8 *)((u8 *)this + 0x1682E)) == MSGMODE_NONE)) ||
                 (((*(u16 *)((u8 *)this + 0x16810)) == 0xFF) && ((*(u8 *)((u8 *)this + 0x1682E)) == MSGMODE_TEXT_DONE) &&
                  ((*(u8 *)((u8 *)this + 0x1692C)) == TEXTBOX_ENDTYPE_PAUSE_MENU)) ||
                 (((*(u16 *)((u8 *)this + 0x16810)) >= 0x100) && ((*(u16 *)((u8 *)this + 0x16810)) <= 0x200))) &&
                (this->gameOverCtx.state == GAMEOVER_INACTIVE)) {
                KaleidoSetup_Update(this);
            }

            sp5C = IS_PAUSED(&this->pauseCtx);

            AnimTaskQueue_Reset(&this->animTaskQueue);
            Object_UpdateEntries(&this->objectCtx);

            if (!sp5C && (IREG(72) == 0)) {
                this->gameplayFrames++;
                Rumble_SetUpdateEnabled(true);

                if ((this->actorCtx.freezeFlashTimer != 0) && (this->actorCtx.freezeFlashTimer-- < 5)) {
                    freezeFlashTimer = this->actorCtx.freezeFlashTimer;
                    if ((freezeFlashTimer > 0) && ((freezeFlashTimer % 2) != 0)) {
                        this->envCtx.fillScreen = true;
                        this->envCtx.screenFillColor[0] = this->envCtx.screenFillColor[1] =
                            this->envCtx.screenFillColor[2] = 150;
                        this->envCtx.screenFillColor[3] = 80;
                    } else {
                        this->envCtx.fillScreen = false;
                    }
                } else {
                    Room_ProcessRoomRequest(this, &this->roomCtx);
                    CollisionCheck_AT(this, &this->colChkCtx);
                    CollisionCheck_OC(this, &this->colChkCtx);
                    CollisionCheck_Damage(this, &this->colChkCtx);
                    CollisionCheck_ClearContext(this, &this->colChkCtx);
                    if (!this->haltAllActors) {
                        Actor_UpdateAll(this, &this->actorCtx);
                    }
                    Cutscene_UpdateManual(this, &this->csCtx);
                    Cutscene_UpdateScripted(this, &this->csCtx);
                    Effect_UpdateAll(this);
                    EffectSs_UpdateAll(this);
                    EffFootmark_Update(this);
                }
            } else {
                Rumble_SetUpdateEnabled(false);
            }

            Room_Noop(this, &this->roomCtx.curRoom, &input[1], 0);
            Room_Noop(this, &this->roomCtx.prevRoom, &input[1], 1);
            Skybox_Update(&this->skyboxCtx);

            if (IS_PAUSED(&this->pauseCtx)) {
                KaleidoScopeCall_Update(this);
            } else if (this->gameOverCtx.state != GAMEOVER_INACTIVE) {
                GameOver_Update(this);
            }

            Message_Update(this);
            Interface_Update(this);
            AnimTaskQueue_Update(this, &this->animTaskQueue);
            SoundSource_UpdateAll(this);
            ShrinkWindow_Update(this->state.framerateDivisor);
            TransitionFade_Update(&this->unk_18E48, this->state.framerateDivisor);
        }
    }

    if (!sp5C || gDbgCamEnabled) {
        s32 i;

        this->nextCamera = this->activeCamId;
        for (i = 0; i < NUM_CAMS; i++) {
            if ((i != this->nextCamera) && (this->cameraPtrs[i] != NULL)) {
                Camera_Update(this->cameraPtrs[i]);
            }
        }
        Camera_Update(this->cameraPtrs[this->nextCamera]);
    }

    if (!sp5C) {
        Play_UpdateWaterCamera(this, this->cameraPtrs[this->nextCamera]);
        Distortion_Update();
    }

    Environment_Update(this, &this->envCtx, &this->lightCtx, &this->pauseCtx, &this->msgCtx, &this->gameOverCtx,
                       this->state.gfxCtx);

    if (this->sramCtx.status != 0) {
        if (gSaveContext.save.isOwlSave) {
            Sram_UpdateWriteToFlashOwlSave(&this->sramCtx);
        } else {
            Sram_UpdateWriteToFlashDefault(&this->sramCtx);
        }
    }
}
