// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/cutscene_camera.h"

s16 CutsceneCamera_Interp_Geo(Vec3f* camPos, f32* camFov, s16* camRoll, CsCmdCamPoint* pointCmd, CsCmdCamMisc* miscCmd,
                              CutsceneCameraInterp* interpState) {
    VecGeo sp40;
    f32 lerp;
    f32 tmp1;
    f32 tmp2;

    if (interpState->type != CS_CAM_INTERP_GEO) {
        
        interpState->type = CS_CAM_INTERP_GEO;
        interpState->waypoint = 0;
        interpState->curFrame = 0;
        interpState->duration = 1;
        if (camPos != NULL) {
            interpState->unk_20 = OLib_Vec3fDist(&interpState->curPos, camPos) * Math_FTanF(DEG_TO_RAD(*camFov));
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
        sp40 = OLib_Vec3fDiffToVecGeo(&interpState->curPos, camPos);
        sp40.r = interpState->unk_20 / Math_FTanF(DEG_TO_RAD(*camFov));
        *camPos = OLib_AddVecGeoToVec3f(&interpState->curPos, &sp40);
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
