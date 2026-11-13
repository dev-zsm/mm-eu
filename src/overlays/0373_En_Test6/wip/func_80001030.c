// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnTest6_InvertedSoTCutscene), score 3.00 (3 differ, size +2)
#include "generated/mm/z_en_test6.h"

void func_80001030(EnTest6* this, PlayState* play) {
    Input* input = CONTROLLER1(&play->state);
    s16 clockYaw;
    Player* player = GET_PLAYER(play);
    Camera* mainCam;
    Vec3f subCamAt;
    Vec3f subCamEye;
    Vec3f eyeNext;
    s32 i;
    f32 temp;
    Camera* subCam;

    subCam = Play_GetCamera(play, this->subCamId);
    mainCam = Play_GetCamera(play, CAM_ID_MAIN);

    
    switch (this->cueId) {
        case SOTCS_CUEID_INV_INIT:
            this->drawType = SOTCS_DRAW_INVERTED_SOT;
            this->invSoTEnvLerp = 0.0f;
            this->speed = 0.1f;
            this->alpha = 0;
            this->invSoTClockYaw = 0;
            this->cueId = SOTCS_CUEID_INV_SETUP_CLOCKS;
            break;

        case SOTCS_CUEID_INV_SETUP_CLOCKS:
            this->invSoTEnvLerp += this->speed;
            Environment_LerpAmbientColor(play, &sInvSoTCsAmbientColor, this->invSoTEnvLerp);
            Environment_LerpDiffuseColor(play, &sInvSoTCsDiffuseColor, this->invSoTEnvLerp);
            Environment_LerpFogColor(play, &sInvSoTCsFogColor, this->invSoTEnvLerp);
            Environment_LerpFog(play, sInvSoTCsFogNear, sInvSoTCsZFar, this->invSoTEnvLerp);

            if (this->timer == 90) {
                this->alpha = 0;
                if (SOTCS_GET_OCARINA_MODE(&this->actor) == OCARINA_MODE_APPLY_INV_SOT_FAST) {
                    this->clockAngle = 0x200;
                    this->clockDist = 0.0f;
                    temp = -100.0f;
                } else {
                    this->clockAngle = 0x570;
                    this->clockDist = 110.0f;
                    temp = 100.0f;
                }
                this->speed = 1.0f;

                for (i = 0; i < SOTCS_INV_NUM_CLOCKS; i++) {
                    this->invSoTClockPos[i].x = player->actor.world.pos.x;
                    this->invSoTClockPos[i].y = player->actor.world.pos.y;
                    this->invSoTClockPos[i].z = player->actor.world.pos.z;
                }

                this->invSoTParticles = ZeldaArena_Malloc(sizeof(Vec3f) * SOTCS_NUM_PARTICLES);
                if (this->invSoTParticles != NULL) {
                    for (i = 0; i < ARRAY_COUNT(this->invSoTParticles[0]); i++) {
                        (*this->invSoTParticles)[i].x = (((2.0f * Rand_ZeroOne()) - 1.0f) * 40.0f) + subCam->eye.x +
                                                        ((subCam->at.x - subCam->eye.x) * 0.2f);
                        (*this->invSoTParticles)[i].y = (((2.0f * Rand_ZeroOne()) - 1.0f) * 120.0f) + subCam->eye.y +
                                                        ((subCam->at.y - subCam->eye.y) * 0.2f) + temp;
                        (*this->invSoTParticles)[i].z = (((2.0f * Rand_ZeroOne()) - 1.0f) * 40.0f) + subCam->eye.z +
                                                        ((subCam->at.z - subCam->eye.z) * 0.2f);
                    }
                }

                EnTest6_EnableMotionBlur(120);
                Distortion_Request(DISTORTION_TYPE_SONG_OF_TIME);
                Distortion_SetDuration(80);

                play->soaringCsOrSoTCsPlaying = true;
                this->cueId = SOTCS_CUEID_INV_CLOCKS;
            }
            break;

        case SOTCS_CUEID_INV_CLOCKS:
            if (this->timer > 80) {
                this->alpha += 25;
            }

            if (this->timer < 20) {
                this->alpha -= 25;
            }

            Environment_LerpAmbientColor(play, &sInvSoTCsAmbientColor, this->invSoTEnvLerp);
            Environment_LerpDiffuseColor(play, &sInvSoTCsDiffuseColor, this->invSoTEnvLerp);
            Environment_LerpFogColor(play, &sInvSoTCsFogColor, this->invSoTEnvLerp);
            Environment_LerpFog(play, sInvSoTCsFogNear + this->alpha, sInvSoTCsZFar + this->alpha, this->invSoTEnvLerp);

            this->invSoTClockYaw -= this->clockAngle;
            clockYaw = this->invSoTClockYaw;

            if (SOTCS_GET_OCARINA_MODE(&this->actor) == OCARINA_MODE_APPLY_INV_SOT_FAST) {
                this->clockAngle += 8;
                this->clockDist += this->speed;
            } else {
                this->clockAngle -= 8;
                this->clockDist -= this->speed;
            }

            for (i = 0; i < SOTCS_INV_NUM_CLOCKS; i++) {
                clockYaw += 0x10000 / SOTCS_INV_NUM_CLOCKS;
                this->invSoTClockPos[i].x = player->actor.world.pos.x + (Math_SinS(clockYaw) * this->clockDist);
                this->invSoTClockPos[i].y = player->actor.world.pos.y;
                this->invSoTClockPos[i].z = player->actor.world.pos.z + (Math_CosS(clockYaw) * this->clockDist);
            }

            if (this->invSoTParticles != NULL) {
                for (i = 0; i < ARRAY_COUNT(this->invSoTParticles[0]); i++) {
                    
                    (*this->invSoTParticles)[i].x += 2.0f * ((2.0f * Rand_ZeroOne()) - 1.0f);

                    
                    if (SOTCS_GET_OCARINA_MODE(&this->actor) == OCARINA_MODE_APPLY_INV_SOT_FAST) {
                        
                        (*this->invSoTParticles)[i].y += 1.0f;
                    } else {
                        
                        (*this->invSoTParticles)[i].y -= 1.0f;
                    }
                    
                    (*this->invSoTParticles)[i].z += 2.0f * ((2.0f * Rand_ZeroOne()) - 1.0f);
                }
            }

            if (this->timer == 10) {
                this->speed = 0.1f;
                EnTest6_DisableMotionBlur();
                Distortion_RemoveRequest(DISTORTION_TYPE_SONG_OF_TIME);
                play->soaringCsOrSoTCsPlaying = false;
                if (this->invSoTParticles != NULL) {
                    ZeldaArena_Free(this->invSoTParticles);
                }
                this->cueId = SOTCS_CUEID_INV_END;
            }
            break;

        case SOTCS_CUEID_INV_END:
            this->invSoTEnvLerp -= this->speed;
            Environment_LerpAmbientColor(play, &sInvSoTCsAmbientColor, this->invSoTEnvLerp);
            Environment_LerpDiffuseColor(play, &sInvSoTCsDiffuseColor, this->invSoTEnvLerp);
            Environment_LerpFogColor(play, &sInvSoTCsFogColor, this->invSoTEnvLerp);
            Environment_LerpFog(play, sInvSoTCsFogNear, sInvSoTCsZFar, this->invSoTEnvLerp);
            break;

        default:
            break;
    }

    
    if (this->screenFillAlpha != 0) {
        Player_SetCsActionWithHaltedActors(play, NULL, PLAYER_CSACTION_WAIT);
    } else {
        if (this->timer == 90) {
            
            
            Player_SetCsActionWithHaltedActors(play, NULL, PLAYER_CSACTION_66);
        }

        if (this->timer == 70) {
            
            
            Player_SetCsActionWithHaltedActors(play, NULL, PLAYER_CSACTION_82);
        }

        if (this->timer == 30) {
            
            
            Player_SetCsActionWithHaltedActors(play, NULL, PLAYER_CSACTION_81);
        }

        if (this->timer == 5) {
            
            
            Player_SetCsActionWithHaltedActors(play, NULL, PLAYER_CSACTION_74);
        }
    }

    
    if (this->timer > 80) {
        subCam->fov += (90.0f - subCam->fov) / (this->timer - 80);
    } else if (this->timer > 60) {
        temp = 1.0f / (this->timer - 60);

        subCamAt.x = subCam->at.x + ((player->actor.world.pos.x - subCam->at.x) * temp);
        subCamAt.y = subCam->at.y + (((player->actor.focus.pos.y - subCam->at.y) - 20.0f) * temp);
        subCamAt.z = subCam->at.z + ((player->actor.world.pos.z - subCam->at.z) * temp);

        eyeNext.x = subCamAt.x + (Math_SinS(player->actor.world.rot.y) * 80.0f);
        eyeNext.y = subCamAt.y + 20.0f;
        eyeNext.z = subCamAt.z + (Math_CosS(player->actor.world.rot.y) * 80.0f);
        temp *= 0.75f;

        VEC3F_LERPIMPDST(&subCamEye, &subCam->eye, &eyeNext, temp);

        Play_SetCameraAtEye(play, this->subCamId, &subCamAt, &subCamEye);
    } else if ((this->timer < 11) && (this->timer > 0)) {
        subCam->fov += (mainCam->fov - subCam->fov) / this->timer;
    }

    
    if (this->screenFillAlpha != 0) {
        
        if (1) {}

        EnTest6_EnableWhiteFillScreen(play, this->screenFillAlpha * 0.05f);
        subCam->fov += (mainCam->fov - subCam->fov) * 0.05f;
        this->screenFillAlpha++;
        if (this->screenFillAlpha >= 20) {
            this->timer = 1;
        }
    } else if ((this->timer <= 60) && (this->timer > 40) &&
               (CHECK_BTN_ALL(input->press.button, BTN_A) || CHECK_BTN_ALL(input->press.button, BTN_B))) {
        this->screenFillAlpha = 1;

        if (SOTCS_GET_OCARINA_MODE(&this->actor) == OCARINA_MODE_APPLY_INV_SOT_SLOW) {
            AudioSfx_StopById(NA_SE_SY_TIME_CONTROL_SLOW);
        } else if (SOTCS_GET_OCARINA_MODE(&this->actor) == OCARINA_MODE_APPLY_INV_SOT_FAST) {
            AudioSfx_StopById(NA_SE_SY_TIME_CONTROL_NORMAL);
        }
    }

    if (DECR(this->timer) == 0) {
        EnTest6_StopInvertedSoTCutscene(this, play);
        play->msgCtx.ocarinaMode = OCARINA_MODE_END;
    }
}
