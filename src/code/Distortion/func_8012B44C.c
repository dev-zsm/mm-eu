// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_quake.h"

void Distortion_Update(void) {
    static s16 depthPhase = 0x3F0;
    static s16 screenPlanePhase = 0x156;
    static s16 duration = 1;
    f32 xyScaleFactor;
    f32 zScaleFactor;
    f32 speedScaleFactor;
    f32 countdownRatio;
    f32 waterYScaleFactor;
    f32 depthPhaseStep;
    f32 screenPlanePhaseStep;
    f32 rotX;
    f32 rotY;
    f32 rotZ;
    f32 xScale;
    f32 yScale;
    f32 zScale;
    f32 speed;
    Player* player;
    PlayState* play = sDistortionRequest.play;
    PosRot playerPosRot;
    Camera* camera = GET_ACTIVE_CAM(play);
    f32 speedRatio = CLAMP_MAX(camera->speedRatio, 1.0f);

    if (sDistortionRequest.type != 0) {
        if (sDistortionRequest.type & DISTORTION_TYPE_MASK_TRANSFORM_2) {
            sDistortionRequest.timer = 2;
            depthPhase = 0x3F0;
            screenPlanePhase = 0x156;

            depthPhaseStep = 0.0f;
            screenPlanePhaseStep = 170.0f;

            rotX = 0.0f;
            rotY = 0.0f;
            rotZ = 0.0f;

            xScale = -0.01f;
            yScale = 0.01f;
            zScale = 0.0f;

            speed = 0.6f;
            xyScaleFactor = zScaleFactor = sDistortionRequest.timer / 60.0f;
            speedScaleFactor = 1.0f;
        } else if (sDistortionRequest.type & DISTORTION_TYPE_BOSS_WARP) {
            if (sDistortionRequest.state == DISTORTION_SETUP) {
                duration = sDistortionRequest.timer;
                depthPhase = 0x3F0;
                screenPlanePhase = 0x156;
            }

            depthPhaseStep = 0.0f;
            screenPlanePhaseStep = 50.0f / duration;

            rotX = 0.0f;
            rotY = 0.0f;
            rotZ = 0.0f;

            xScale = 0.01f;
            yScale = 100.0f;
            zScale = 0.0f;

            speed = 0.4f;
            xyScaleFactor = zScaleFactor = ((f32)duration - sDistortionRequest.timer) / (f32)duration;
            speedScaleFactor = 0.5f;
        } else if (sDistortionRequest.type & DISTORTION_TYPE_MASK_TRANSFORM_1) {
            if (sDistortionRequest.state == DISTORTION_SETUP) {
                duration = sDistortionRequest.timer;
                depthPhase = 0x1FC;
                screenPlanePhase = 0x156;
            }

            depthPhaseStep = -5.0f;
            screenPlanePhaseStep = 5.0f;

            rotX = 0.0f;
            rotY = 0.0f;
            rotZ = 2.0f;

            xScale = 0.3f;
            yScale = 0.3f;
            zScale = 0.0f;

            speed = 0.1f;
            xyScaleFactor = zScaleFactor = ((f32)duration - sDistortionRequest.timer) / (f32)duration;
            speedScaleFactor = 1.0f;
        } else if (sDistortionRequest.type & DISTORTION_TYPE_GORON_BUTT) {
            if (sDistortionRequest.state == DISTORTION_SETUP) {
                duration = sDistortionRequest.timer;
                depthPhase = 0x2710;
                screenPlanePhase = 0x3E8;
            }

            depthPhaseStep = 0.0f;
            screenPlanePhaseStep = 150.0f;

            rotX = 0;
            rotY = 0;
            rotZ = 0.2f;

            xScale = 0.025f;
            yScale = 0.02f;
            zScale = 0.01f;

            speed = 1.5f;
            if (sDistortionRequest.timer < 5) {
                xyScaleFactor = zScaleFactor = ((f32)duration - sDistortionRequest.timer) / (f32)duration;
            } else {
                xyScaleFactor = zScaleFactor = 0.0f;
            }
            speedScaleFactor = 1.0f;
        } else if (sDistortionRequest.type & DISTORTION_TYPE_UNK_ATTACK) {
            if (sDistortionRequest.state == DISTORTION_SETUP) {
                duration = sDistortionRequest.timer;
                depthPhase = 0x4B0;
                screenPlanePhase = 0x7D0;
            }

            depthPhaseStep = 0.0f;
            screenPlanePhaseStep = 150.0f;

            rotX = 0;
            rotY = 0;
            rotZ = 0;

            xScale = 0.03f;
            yScale = 0.02f;
            zScale = 0.01f;

            speed = 1.5f;
            xyScaleFactor = zScaleFactor = sDistortionRequest.timer / (f32)duration;
            speedScaleFactor = 1.0f;
        } else if (sDistortionRequest.type & DISTORTION_TYPE_ZORA_KICK) {
            if (sDistortionRequest.state == DISTORTION_SETUP) {
                duration = sDistortionRequest.timer;
                depthPhase = 0x9C4;
                screenPlanePhase = 0xBB8;
            }

            depthPhaseStep = 0.0f;
            screenPlanePhaseStep = 150.0f;

            rotX = 0;
            rotY = 0;
            rotZ = 0;

            xScale = 0.03f;
            yScale = 0.03f;
            zScale = 0.01f;

            speed = 1.3f;
            if (sDistortionRequest.timer < 4) {
                xyScaleFactor = zScaleFactor = sDistortionRequest.timer / (f32)duration;
            } else {
                xyScaleFactor = zScaleFactor = 0.0f;
            }
            speedScaleFactor = 1.0f;
        } else if (sDistortionRequest.type & DISTORTION_TYPE_SONG_OF_TIME) {
            sDistortionRequest.timer = 2;
            if (sDistortionRequest.state == DISTORTION_SETUP) {
                depthPhase = 0x9C4;
                screenPlanePhase = 0xBB8;
            }

            depthPhase += 0xB1;
            screenPlanePhase -= 0x2B;

            depthPhaseStep = -107.0f;
            screenPlanePhaseStep = 158.0f;

            rotX = 0.2f;
            rotY = 1.7f;
            rotZ = -2.9f;

            xScale = -0.6f;
            yScale = -0.7f;
            zScale = 0.6f;

            speed = 0.2f;
            zScaleFactor = 1.0f;
            xyScaleFactor = 1.0f;
            speedScaleFactor = 1.0f;
        } else if (sDistortionRequest.type & DISTORTION_TYPE_UNDERWATER_ENTRY) {
            if (sDistortionRequest.state == DISTORTION_SETUP) {
                duration = sDistortionRequest.timer;
                depthPhase = 0x760;
                screenPlanePhase = 0x1BC;
            }

            depthPhaseStep = 248.0f;
            screenPlanePhaseStep = -90.0f;

            rotX = 0.0f;
            rotY = 0.0f;
            rotZ = 0.0f;

            xScale = -0.4f;
            yScale = 0.4f;
            zScale = 0.2f;

            speed = 0.25f;
            countdownRatio = sDistortionRequest.timer / (f32)duration;
            zScaleFactor = xyScaleFactor = countdownRatio;
            speedScaleFactor = 1.0f;
        } else if (sDistortionRequest.type & DISTORTION_TYPE_ZORA_SWIMMING) {
            depthPhase = 0x3F0;
            screenPlanePhase = 0x156;

            sDistortionRequest.timer = 2;
            player = GET_PLAYER(play);

            if (player != NULL) {
                playerPosRot = Actor_GetWorldPosShapeRot(&player->actor);
            }

            depthPhaseStep = 359.2f;
            screenPlanePhaseStep = -18.5f;

            rotX = 0.0f;
            rotY = 0.0f;
            rotZ = 0.3f;

            switch (Distortion_GetUnderwaterCurrentSpeed(player)) {
                case CONVEYOR_SPEED_FAST:
                    xScale = -0.06f;
                    yScale = 0.1f;
                    zScale = 0.03f;
                    speed = 0.33f;
                    break;

                case CONVEYOR_SPEED_MEDIUM:
                    xScale = -0.06f;
                    yScale = 0.1f;
                    zScale = 0.03f;
                    speed = 0.33f;
                    break;

                case CONVEYOR_SPEED_SLOW:
                    xScale = -0.06f;
                    yScale = 0.1f;
                    zScale = 0.03f;
                    speed = 0.33f;
                    break;

                default:
                    xScale = -0.06f;
                    yScale = 0.1f;
                    zScale = 0.03f;
                    speed = 0.23f;
                    break;
            }

            if (player->unk_B86[1] < 0) {
                xyScaleFactor = (player->unk_B86[1] - (f32)0x4000) / (f32)0xC000;
            } else {
                xyScaleFactor = (player->unk_B86[1] + (f32)0x4000) / (f32)0xC000;
            }
            zScaleFactor = -xyScaleFactor;
            speedScaleFactor = 1.0f;
        } else if (sDistortionRequest.type & DISTORTION_TYPE_NON_ZORA_SWIMMING) {
            depthPhase = 0x3F0;
            screenPlanePhase = 0x156;

            sDistortionRequest.timer = 2;
            player = GET_PLAYER(play);

            depthPhaseStep = 359.2f;
            screenPlanePhaseStep = -18.5f;

            rotX = 0.0f;
            rotY = 0.0f;
            rotZ = 0.0f;
            switch (Distortion_GetUnderwaterCurrentSpeed(player)) {
                case CONVEYOR_SPEED_FAST:
                    xScale = 0.12f;
                    yScale = 0.12f;
                    zScale = 0.08f;
                    speed = 0.18f;
                    break;

                case CONVEYOR_SPEED_MEDIUM:
                    xScale = 0.12f;
                    yScale = 0.12f;
                    zScale = 0.08f;
                    speed = 0.12f;
                    break;

                case CONVEYOR_SPEED_SLOW:
                    xScale = 0.12f;
                    yScale = 0.12f;
                    zScale = 0.08f;
                    speed = 0.08f;
                    break;

                default:
                    xScale = 0.12f;
                    yScale = 0.12f;
                    zScale = 0.08f;
                    speed = 0.05f;
                    break;
            }

            if ((camera->waterYPos - camera->eye.y) > 2000.0f) {
                waterYScaleFactor = 1.0f;
            } else {
                waterYScaleFactor = (camera->waterYPos - camera->eye.y) / 2000.0f;
            }

            xyScaleFactor = speedScaleFactor = (waterYScaleFactor * 0.15f) + 0.35f + (speedRatio * 0.4f);
            zScaleFactor = 0.9f - xyScaleFactor;
        } else if (sDistortionRequest.type & DISTORTION_TYPE_HOT_ROOM) {
            
            depthPhase = 0x3F0;
            screenPlanePhase = 0x156;

            sDistortionRequest.timer = 2;
            depthPhaseStep = 0.0f;
            screenPlanePhaseStep = 150.0f;

            rotX = 0.0f;
            rotY = 0.0f;
            rotZ = 0.0f;

            xScale = -0.01f;
            yScale = 0.01f;
            zScale = 0.01f;

            speed = 0.6f;
            speedScaleFactor = 1.0f;
            zScaleFactor = 1.0f;
            xyScaleFactor = 1.0f;
        } else {
            return;
        }

        depthPhase += CAM_DEG_TO_BINANG(depthPhaseStep);
        screenPlanePhase += CAM_DEG_TO_BINANG(screenPlanePhaseStep);

        View_SetDistortionOrientation(&sDistortionRequest.play->view,
                                      Math_CosS(depthPhase) * (DEG_TO_RAD(rotX) * xyScaleFactor),
                                      Math_SinS(depthPhase) * (DEG_TO_RAD(rotY) * xyScaleFactor),
                                      Math_SinS(screenPlanePhase) * (DEG_TO_RAD(rotZ) * zScaleFactor));
        View_SetDistortionScale(&sDistortionRequest.play->view,
                                (Math_SinS(screenPlanePhase) * (xScale * xyScaleFactor)) + 1.0f,
                                (Math_CosS(screenPlanePhase) * (yScale * xyScaleFactor)) + 1.0f,
                                (Math_CosS(depthPhase) * (zScale * zScaleFactor)) + 1.0f);
        View_SetDistortionSpeed(&sDistortionRequest.play->view, speed * speedScaleFactor);

        sDistortionRequest.state = DISTORTION_ACTIVE;

    } else if (sDistortionRequest.state != DISTORTION_INACTIVE) {
        View_ClearDistortion(&play->view);

        sDistortionRequest.state = DISTORTION_INACTIVE;
        sDistortionRequest.timer = 0;
    }

    if (sDistortionRequest.timer != 0) {
        sDistortionRequest.timer--;
        if (sDistortionRequest.timer == 0) {
            sDistortionRequest.type = 0;
        }
    }
}
