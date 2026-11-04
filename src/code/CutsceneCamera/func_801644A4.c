// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/cutscene_camera.h"

s16 CutsceneCamera_Interp_Unused(Vec3f* camPos, f32* camFov, s16* camRoll, CsCmdCamPoint* pointCmd,
                                 CsCmdCamMisc* miscCmd, CutsceneCameraInterp* interpState) {
    s32 index;
    f32 coeff[3];

    if (interpState->type != CS_CAM_INTERP_MP_CUBIC) {
        
        interpState->type = CS_CAM_INTERP_MP_CUBIC;
        interpState->waypoint = 0;
        interpState->duration = pointCmd->duration;
        ref_func_80162FF8(interpState->duration);
        interpState->curFrame = 0;
    }

    index = interpState->waypoint + 2;
    ref_func_801631DC(F32_LERPIMP(sCsCamKnots[index], sCsCamKnots[index + 1],
                              (f32)interpState->curFrame / miscCmd[interpState->waypoint].unused0),
                  index, coeff);

    if (camPos != NULL) {
        camPos->x = (coeff[0] * pointCmd[interpState->waypoint].pos.x) +
                    (coeff[1] * pointCmd[interpState->waypoint + 1].pos.x) +
                    (coeff[2] * pointCmd[interpState->waypoint + 2].pos.x);
        camPos->y = (coeff[0] * pointCmd[interpState->waypoint].pos.y) +
                    (coeff[1] * pointCmd[interpState->waypoint + 1].pos.y) +
                    (coeff[2] * pointCmd[interpState->waypoint + 2].pos.y);
        camPos->z = (coeff[0] * pointCmd[interpState->waypoint].pos.z) +
                    (coeff[1] * pointCmd[interpState->waypoint + 1].pos.z) +
                    (coeff[2] * pointCmd[interpState->waypoint + 2].pos.z);
    }

    if (camFov != NULL) {
        *camFov = (coeff[0] * miscCmd[interpState->waypoint].fov) +
                  (coeff[1] * miscCmd[interpState->waypoint + 1].fov) +
                  (coeff[2] * miscCmd[interpState->waypoint + 2].fov);
    }

    if (camRoll != NULL) {
        *camRoll = CAM_DEG_TO_BINANG((coeff[0] * miscCmd[interpState->waypoint].roll) +
                                     (coeff[1] * miscCmd[interpState->waypoint + 1].roll) +
                                     (coeff[2] * miscCmd[interpState->waypoint + 2].roll));
    }

    interpState->curFrame++;

    if (interpState->curFrame >= miscCmd[interpState->waypoint].unused0) {
        interpState->waypoint++;
        interpState->curFrame = 0;
        if (interpState->waypoint >= (interpState->duration - 2)) {
            interpState->type = CS_CAM_INTERP_OFF;
            return interpState->duration;
        }
    }
    return 0;
}
