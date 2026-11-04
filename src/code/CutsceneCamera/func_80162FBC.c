// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/cutscene_camera.h"

s16 CutsceneCamera_Interp_Scale(Vec3f* camPos, f32* camFov, s16* camRoll, CsCmdCamPoint* pointCmd,
                                CsCmdCamMisc* miscCmd, CutsceneCameraInterp* interpState) {
    f32 lerp;
    f32 tmp1;
    f32 tmp2;

    if (interpState->type != CS_CAM_INTERP_SCALE) {
        
        interpState->type = CS_CAM_INTERP_SCALE;
        interpState->waypoint = 0;
        interpState->curFrame = 0;
        interpState->duration = 1;
        if (camPos != NULL) {
            interpState->initPos.x = camPos->x;
            interpState->initPos.y = camPos->y;
            interpState->initPos.z = camPos->z;
        }
        if (camFov != NULL) {
            interpState->initFov = *camFov;
        }
        if (camRoll != NULL) {
            interpState->initRoll = *camRoll;
        }
    }

    tmp2 = (((pointCmd->weight + 100) * (pointCmd->duration / 2)) +
            (((pointCmd->weight + 100) / 2) * (pointCmd->duration & 1)));
    if (pointCmd->duration < 2) {
        lerp = 1.0f;
    } else {
        tmp1 = (f32)(pointCmd->weight - 100) / (pointCmd->duration - 1);
        lerp = ((interpState->curFrame * tmp1) + 100.0f) / tmp2;
    }

    interpState->curFrame++;

    if (camPos != NULL) {
        camPos->x += (pointCmd->pos.x - interpState->initPos.x) * lerp;
        camPos->y += (pointCmd->pos.y - interpState->initPos.y) * lerp;
        camPos->z += (pointCmd->pos.z - interpState->initPos.z) * lerp;
    }

    if (camFov != NULL) {
        *camFov += (miscCmd->fov - interpState->initFov) * lerp;
    }

    if (camRoll != NULL) {
        s16 targetRoll;
        s16 rollDiffToTarget;

        targetRoll = CAM_DEG_TO_BINANG(miscCmd->roll);

        rollDiffToTarget = (s16)(targetRoll - TRUNCF_BINANG(interpState->initRoll));

        *camRoll += TRUNCF_BINANG(rollDiffToTarget * lerp);
    }

    if (interpState->curFrame >= pointCmd->duration) {
        
        interpState->type = CS_CAM_INTERP_OFF;
        return 1;
    }

    return 0;
}
