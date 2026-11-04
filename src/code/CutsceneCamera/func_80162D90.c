// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/cutscene_camera.h"

s16 CutsceneCamera_Interp_Linear(Vec3f* camPos, f32* camFov, s16* camRoll, CsCmdCamPoint* pointCmd,
                                 CsCmdCamMisc* miscCmd, CutsceneCameraInterp* interpState) {
    f32 lerp;

    if (interpState->type != CS_CAM_INTERP_LINEAR) {
        
        interpState->type = CS_CAM_INTERP_LINEAR;
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

    interpState->curFrame++;

    lerp = ((f32)interpState->curFrame / pointCmd->duration) * (pointCmd->weight / 100.0f);

    if (camPos != NULL) {
        VEC3F_LERPIMPDST(camPos, &interpState->initPos, &pointCmd->pos, lerp);
    }

    if (camFov != NULL) {
        *camFov = LERPIMP(interpState->initFov, miscCmd->fov, lerp);
    }

    if (camRoll != NULL) {
        s16 targetRoll;
        s16 rollDiffToTarget;

        targetRoll = CAM_DEG_TO_BINANG(miscCmd->roll);

        rollDiffToTarget = (s16)(targetRoll - TRUNCF_BINANG(interpState->initRoll));

        *camRoll = TRUNCF_BINANG(interpState->initRoll) + TRUNCF_BINANG(rollDiffToTarget * lerp);
    }

    if (interpState->curFrame >= pointCmd->duration) {
        
        interpState->type = CS_CAM_INTERP_OFF;
        return 1;
    }

    return 0;
}
