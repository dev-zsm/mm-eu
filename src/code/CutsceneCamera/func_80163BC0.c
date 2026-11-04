// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/cutscene_camera.h"

s16 CutsceneCamera_Interp_MultiPointCubic(Vec3f* camPos, f32* camFov, s16* camRoll, CsCmdCamPoint* pointCmd,
                                          CsCmdCamMisc* miscCmd, CutsceneCameraInterp* interpState) {
    f32 new_var;
    f32 coeff[4];
    s32 waypoints[4];

    if (interpState->type != CS_CAM_INTERP_MP_CUBIC) {
        
        interpState->type = CS_CAM_INTERP_MP_CUBIC;
        interpState->waypoint = 0;
        interpState->duration = pointCmd->duration;
        interpState->curFrame = 0;
    }

    new_var = (f32)interpState->curFrame / pointCmd[interpState->waypoint + 1].duration;

    if (interpState->waypoint < (interpState->duration - 1)) {
        waypoints[0] = interpState->waypoint;
    } else {
        waypoints[0] = interpState->duration - 1;
    }

    if ((interpState->waypoint + 1) < (interpState->duration - 1)) {
        waypoints[1] = interpState->waypoint + 1;
    } else {
        waypoints[1] = interpState->duration - 1;
    }

    if ((interpState->waypoint + 2) < (interpState->duration - 1)) {
        waypoints[2] = interpState->waypoint + 2;
    } else {
        waypoints[2] = interpState->duration - 1;
    }

    if ((interpState->waypoint + 3) < (interpState->duration - 1)) {
        waypoints[3] = interpState->waypoint + 3;
    } else {
        waypoints[3] = interpState->duration - 1;
    }

    ref_func_801629BC(new_var, coeff);

    if (camPos != NULL) {
        camPos->x = (coeff[0] * pointCmd[waypoints[0]].pos.x) + (coeff[1] * pointCmd[waypoints[1]].pos.x) +
                    (coeff[2] * pointCmd[waypoints[2]].pos.x) + (coeff[3] * pointCmd[waypoints[3]].pos.x);
        camPos->y = (coeff[0] * pointCmd[waypoints[0]].pos.y) + (coeff[1] * pointCmd[waypoints[1]].pos.y) +
                    (coeff[2] * pointCmd[waypoints[2]].pos.y) + (coeff[3] * pointCmd[waypoints[3]].pos.y);
        camPos->z = (coeff[0] * pointCmd[waypoints[0]].pos.z) + (coeff[1] * pointCmd[waypoints[1]].pos.z) +
                    (coeff[2] * pointCmd[waypoints[2]].pos.z) + (coeff[3] * pointCmd[waypoints[3]].pos.z);
    }

    if (camFov != NULL) {
        *camFov = (coeff[0] * miscCmd[waypoints[0]].fov) + (coeff[1] * miscCmd[waypoints[1]].fov) +
                  (coeff[2] * miscCmd[waypoints[2]].fov) + (coeff[3] * miscCmd[waypoints[3]].fov);
    }

    if (camRoll != NULL) {
        s16 targetRolls[4];
        s32 sp2C[3];
        s32 rollDiffToTarget;

        targetRolls[0] = CAM_DEG_TO_BINANG(miscCmd[waypoints[0]].roll);
        targetRolls[1] = CAM_DEG_TO_BINANG(miscCmd[waypoints[1]].roll);
        targetRolls[2] = CAM_DEG_TO_BINANG(miscCmd[waypoints[2]].roll);
        targetRolls[3] = CAM_DEG_TO_BINANG(miscCmd[waypoints[3]].roll);

        sp2C[0] = (s16)(targetRolls[1] - targetRolls[0]);
        sp2C[1] = sp2C[0] + (s16)(targetRolls[2] - targetRolls[1]);
        sp2C[2] = sp2C[1] + (s16)(targetRolls[3] - targetRolls[2]);

        rollDiffToTarget = ((coeff[1] * sp2C[0]) + (coeff[2] * sp2C[1]) + (coeff[3] * sp2C[2]));
        *camRoll = targetRolls[0] + rollDiffToTarget;
    }

    interpState->curFrame++;

    if (interpState->curFrame == pointCmd[interpState->waypoint + 1].duration) {
        interpState->curFrame = 0;
        interpState->waypoint++;
        if (interpState->waypoint >= (interpState->duration - 3)) {
            interpState->type = CS_CAM_INTERP_OFF;
            return interpState->duration;
        }
    }
    return 0;
}
