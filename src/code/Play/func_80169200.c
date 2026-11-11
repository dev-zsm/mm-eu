// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_play.h"

void Play_DrawMain(PlayState* this) {
    GraphicsContext* gfxCtx = this->state.gfxCtx;
    Lights* lights;
    Vec3f temp;
    u8 sp25B = false;
    f32 zFar;

    if (R_PAUSE_BG_PRERENDER_STATE >= PAUSE_BG_PRERENDER_UNK4) {
        PreRender_ApplyFiltersSlowlyDestroy(&this->pauseBgPreRender);
        R_PAUSE_BG_PRERENDER_STATE = PAUSE_BG_PRERENDER_OFF;
    }

    if ((R_PAUSE_BG_PRERENDER_STATE <= PAUSE_BG_PRERENDER_SETUP) && (gTransitionTileState <= TRANS_TILE_SETUP)) {
        if (this->skyboxCtx.shouldDraw || (this->roomCtx.curRoom.roomShape->base.type == ROOM_SHAPE_TYPE_IMAGE)) {
            ref_func_8012CF0C(gfxCtx, false, true, 0, 0, 0);
        } else {
            ref_func_8012CF0C(gfxCtx, true, true, this->lightCtx.fogColor[0], this->lightCtx.fogColor[1],
                          this->lightCtx.fogColor[2]);
        }
    } else {
        ref_func_8012CF0C(gfxCtx, false, false, 0, 0, 0);
    }

    OPEN_DISPS(gfxCtx);

    gSegments[0x04] = OS_K0_TO_PHYSICAL(this->objectCtx.slots[this->objectCtx.mainKeepSlot].segment);
    gSegments[0x05] = OS_K0_TO_PHYSICAL(this->objectCtx.slots[this->objectCtx.subKeepSlot].segment);
    gSegments[0x02] = OS_K0_TO_PHYSICAL(this->sceneSegment);

    gSPSegment(POLY_OPA_DISP++, 0x04, this->objectCtx.slots[this->objectCtx.mainKeepSlot].segment);
    gSPSegment(POLY_XLU_DISP++, 0x04, this->objectCtx.slots[this->objectCtx.mainKeepSlot].segment);
    gSPSegment(OVERLAY_DISP++, 0x04, this->objectCtx.slots[this->objectCtx.mainKeepSlot].segment);

    gSPSegment(POLY_OPA_DISP++, 0x05, this->objectCtx.slots[this->objectCtx.subKeepSlot].segment);
    gSPSegment(POLY_XLU_DISP++, 0x05, this->objectCtx.slots[this->objectCtx.subKeepSlot].segment);
    gSPSegment(OVERLAY_DISP++, 0x05, this->objectCtx.slots[this->objectCtx.subKeepSlot].segment);

    gSPSegment(POLY_OPA_DISP++, 0x02, this->sceneSegment);
    gSPSegment(POLY_XLU_DISP++, 0x02, this->sceneSegment);
    gSPSegment(OVERLAY_DISP++, 0x02, this->sceneSegment);

    if (1) {
        ShrinkWindow_Draw(gfxCtx);

        POLY_OPA_DISP = Play_SetFog(this, POLY_OPA_DISP);
        POLY_XLU_DISP = Play_SetFog(this, POLY_XLU_DISP);

        zFar = this->lightCtx.zFar;
        if (zFar > 12800.0f) {
            zFar = 12800.0f;
        }

        View_SetPerspective(&this->view, this->view.fovy, this->view.zNear, zFar);

        View_Apply(&this->view, 0xF);

        
        Matrix_MtxToMtxF(&this->view.viewing, &this->billboardMtxF);
        Matrix_MtxToMtxF(&this->view.projection, &this->viewProjectionMtxF);

        this->projectionMtxFDiagonal.x = this->viewProjectionMtxF.xx;
        this->projectionMtxFDiagonal.y = this->viewProjectionMtxF.yy;
        this->projectionMtxFDiagonal.z = -this->viewProjectionMtxF.zz;

        SkinMatrix_MtxFMtxFMult(&this->viewProjectionMtxF, &this->billboardMtxF, &this->viewProjectionMtxF);

        this->billboardMtxF.mf[3][2] = this->billboardMtxF.mf[3][1] = this->billboardMtxF.mf[3][0] =
            this->billboardMtxF.mf[2][3] = this->billboardMtxF.mf[1][3] = this->billboardMtxF.mf[0][3] = 0.0f;

        Matrix_Transpose(&this->billboardMtxF);

        this->billboardMtx = GRAPH_ALLOC(this->state.gfxCtx, 2 * sizeof(Mtx));

        Matrix_MtxFToMtx(&this->billboardMtxF, this->billboardMtx);
        Matrix_RotateYF(BINANG_TO_RAD((s16)(Camera_GetCamDirYaw(GET_ACTIVE_CAM(this)) + 0x8000)), MTXMODE_NEW);
        Matrix_ToMtx(this->billboardMtx + 1);

        gSPSegment(POLY_OPA_DISP++, 0x01, this->billboardMtx);
        gSPSegment(POLY_XLU_DISP++, 0x01, this->billboardMtx);
        gSPSegment(OVERLAY_DISP++, 0x01, this->billboardMtx);

        if (1) {
            Gfx* sp218;
            Gfx* sp214 = POLY_OPA_DISP;

            sp218 = Gfx_Open(sp214);
            gSPDisplayList(OVERLAY_DISP++, sp218);

            if (((this->transitionMode == TRANS_MODE_INSTANCE_RUNNING) ||
                 (this->transitionMode == TRANS_TYPE_INSTANT)) ||
                ref_D_801D0D54) {
                View spA8;

                View_Init(&spA8, gfxCtx);
                spA8.flags = 0xA;

                SET_FULLSCREEN_VIEWPORT(&spA8);

                View_ApplyTo(&spA8, &sp218);
                this->transitionCtx.draw(&this->transitionCtx.instanceData, &sp218);
            }

            TransitionFade_Draw(&this->unk_18E48, &sp218);

            if (gPlayVisMonoColor.a != 0) {
                sPlayVisMono.vis.primColor.rgba = gPlayVisMonoColor.rgba;
                VisMono_Draw(&sPlayVisMono, &sp218);
            }

            gSPEndDisplayList(sp218++);
            Gfx_Close(sp214, sp218);
            POLY_OPA_DISP = sp218;
        }

        if (gTransitionTileState == TRANS_TILE_READY) {
            Gfx* sp90 = POLY_OPA_DISP;

            TransitionTile_Draw(&sTransitionTile, &sp90);
            POLY_OPA_DISP = sp90;
            sp25B = true;
            goto PostWorldDraw;
        }

        PreRender_SetValues(&this->pauseBgPreRender, gCfbWidth, gCfbHeight, gfxCtx->curFrameBuffer, gfxCtx->zbuffer);

        if (R_PAUSE_BG_PRERENDER_STATE == PAUSE_BG_PRERENDER_PROCESS) {
            Sched_FlushTaskQueue();
            if (!gSaveContext.screenScaleFlag) {
                PreRender_ApplyFiltersSlowlyInit(&this->pauseBgPreRender);
            }
            R_PAUSE_BG_PRERENDER_STATE = PAUSE_BG_PRERENDER_READY;
            SREG(33) |= 1;
        } else {
            if (R_PAUSE_BG_PRERENDER_STATE == PAUSE_BG_PRERENDER_READY) {
                Gfx* sp8C = POLY_OPA_DISP;

                if (this->pauseBgPreRender.filterState == PRERENDER_FILTER_STATE_DONE) {
                    PreRender_RestoreFramebuffer(&this->pauseBgPreRender, &sp8C);
                } else {
                    ref_func_80170798(&this->pauseBgPreRender, &sp8C);
                }

                gSPDisplayList(sp8C++, ref_D_0E000000.syncSegments);
                POLY_OPA_DISP = sp8C;
                sp25B = true;
                goto PostWorldDraw;
            }

            if (!this->soaringCsOrSoTCsPlaying) {
                if (1) {
                    if (((u32)this->skyboxId != SKYBOX_NONE) && !this->envCtx.skyboxDisabled) {
                        if ((this->skyboxId == SKYBOX_NORMAL_SKY) || (this->skyboxId == SKYBOX_3)) {
                            Environment_UpdateSkybox(this->skyboxId, &this->envCtx, &this->skyboxCtx);
                            Skybox_Draw(&this->skyboxCtx, gfxCtx, this->skyboxId, this->envCtx.skyboxBlend,
                                        this->view.eye.x, this->view.eye.y, this->view.eye.z);
                        } else if (!this->skyboxCtx.shouldDraw) {
                            Skybox_Draw(&this->skyboxCtx, gfxCtx, this->skyboxId, 0, this->view.eye.x, this->view.eye.y,
                                        this->view.eye.z);
                        }
                    }

                    Environment_Draw(this);
                }

                lights = LightContext_NewLights(&this->lightCtx, gfxCtx);

                if (this->roomCtx.curRoom.enablePosLights || (MREG(93) != 0)) {
                    lights->enablePosLights = true;
                }

                Lights_BindAll(lights, this->lightCtx.listHead, NULL, this);
                Lights_Draw(lights, gfxCtx);

                if (1) {
                    
                    u32 roomDrawFlags = ((1) ? 1 : 0) | (((void)0, 1) ? 2 : 0);

                    Scene_Draw(this);
                    if (this->roomCtx.unk78) {
                        Room_Draw(this, &this->roomCtx.curRoom, roomDrawFlags & 3);
                        Room_Draw(this, &this->roomCtx.prevRoom, roomDrawFlags & 3);
                    }
                }

                if (this->skyboxCtx.shouldDraw) {
                    Vec3f quakeOffset;

                    if (1) {
                        quakeOffset = Camera_GetQuakeOffset(GET_ACTIVE_CAM(this));
                        Skybox_Draw(&this->skyboxCtx, gfxCtx, this->skyboxId, 0, this->view.eye.x + quakeOffset.x,
                                    this->view.eye.y + quakeOffset.y, this->view.eye.z + quakeOffset.z);
                    }
                }

                if (this->envCtx.precipitation[PRECIP_RAIN_CUR] != 0) {
                    Environment_DrawRain(this, &this->view, gfxCtx);
                }
            }

            if (1) {
                Environment_FillScreen(gfxCtx, 0, 0, 0, this->bgCoverAlpha, FILL_SCREEN_OPA);
            }

            if (1) {
                Actor_DrawAll(this, &this->actorCtx);
            }

            if (1) {
                if (!this->envCtx.sunDisabled) {
                    temp.x = this->view.eye.x + this->envCtx.sunPos.x;
                    temp.y = this->view.eye.y + this->envCtx.sunPos.y;
                    temp.z = this->view.eye.z + this->envCtx.sunPos.z;
                    Environment_DrawSunLensFlare(this, &this->envCtx, &this->view, gfxCtx, temp);
                }

                Environment_DrawCustomLensFlare(this);
            }

            if (1) {
                if (R_PLAY_FILL_SCREEN_ON) {
                    Environment_FillScreen(gfxCtx, R_PLAY_FILL_SCREEN_R, R_PLAY_FILL_SCREEN_G, R_PLAY_FILL_SCREEN_B,
                                           R_PLAY_FILL_SCREEN_ALPHA, FILL_SCREEN_OPA | FILL_SCREEN_XLU);
                }

                switch (this->envCtx.fillScreen) {
                    case 1:
                        Environment_FillScreen(gfxCtx, this->envCtx.screenFillColor[0], this->envCtx.screenFillColor[1],
                                               this->envCtx.screenFillColor[2], this->envCtx.screenFillColor[3],
                                               FILL_SCREEN_OPA | FILL_SCREEN_XLU);
                        break;

                    default:
                        break;
                }
            }

            if (1) {
                if (this->envCtx.sandstormState != SANDSTORM_OFF) {
                    Environment_DrawSandstorm(this, this->envCtx.sandstormState);
                }
            }

            if (this->worldCoverAlpha != 0) {
                Environment_FillScreen(gfxCtx, 0, 0, 0, this->worldCoverAlpha, FILL_SCREEN_OPA | FILL_SCREEN_XLU);
            }

            if (1) {
                DebugDisplay_DrawObjects(this);
            }

            Play_DrawMotionBlur(this);

            if ((R_PAUSE_BG_PRERENDER_STATE == PAUSE_BG_PRERENDER_SETUP) ||
                (gTransitionTileState == TRANS_TILE_SETUP) || (R_PICTO_PHOTO_STATE == PICTO_PHOTO_STATE_SETUP)) {
                Gfx* sp74;
                Gfx* sp70 = POLY_OPA_DISP;

                sp74 = Gfx_Open(sp70);
                gSPDisplayList(OVERLAY_DISP++, sp74);
                this->pauseBgPreRender.fbuf = gfxCtx->curFrameBuffer;

                if (R_PAUSE_BG_PRERENDER_STATE == PAUSE_BG_PRERENDER_SETUP) {
                    R_PAUSE_BG_PRERENDER_STATE = PAUSE_BG_PRERENDER_PROCESS;
                    this->pauseBgPreRender.fbufSave = gfxCtx->zbuffer;
                    this->pauseBgPreRender.cvgSave = this->unk_18E58;
                } else if (R_PICTO_PHOTO_STATE == PICTO_PHOTO_STATE_SETUP) {
                    R_PICTO_PHOTO_STATE = PICTO_PHOTO_STATE_PROCESS;
                    this->pauseBgPreRender.fbufSave = gfxCtx->zbuffer;
                    this->pauseBgPreRender.cvgSave = this->unk_18E58;
                } else {
                    gTransitionTileState = TRANS_TILE_PROCESS;
                    this->pauseBgPreRender.fbufSave = gfxCtx->zbuffer;
                    this->pauseBgPreRender.cvgSave = NULL;
                }

                PreRender_SaveFramebuffer(&this->pauseBgPreRender, &sp74);

                if (this->pauseBgPreRender.cvgSave != NULL) {
                    PreRender_DrawCoverage(&this->pauseBgPreRender, &sp74);
                }

                gSPEndDisplayList(sp74++);
                Gfx_Close(sp70, sp74);
                POLY_OPA_DISP = sp74;
                this->unk_18B49 = 2;
                SREG(33) |= 1;
                goto SkipPostWorldDraw;
            }

        PostWorldDraw:
            if (1) {
                Play_PostWorldDraw(this);
            }
        }
    }

SkipPostWorldDraw:

    if ((this->view.unk164 != 0) && !gDbgCamEnabled) {
        Camera_Update(GET_ACTIVE_CAM(this));
        View_UpdateViewingMatrix(&this->view);
        this->view.unk164 = 0;
        if ((this->skyboxId != SKYBOX_NONE) && !this->envCtx.skyboxDisabled) {
            Skybox_UpdateMatrix(&this->skyboxCtx, this->view.eye.x, this->view.eye.y, this->view.eye.z);
        }
    }

    if (!sp25B) {
        Environment_DrawSkyboxStars(this);
    }

    CLOSE_DISPS(gfxCtx);
}
