// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/cutscene_camera.h"

s16 CutsceneCamera_Interp_Set(Vec3f* camPos, f32* camFov, s16* camRoll, CsCmdCamPoint* pointCmd, CsCmdCamMisc* miscCmd,
                              CutsceneCameraInterp* interpState) {
    s16 pad;

    if (interpState->type != CS_CAM_INTERP_SET) {
        
        interpState->type = CS_CAM_INTERP_SET;
        interpState->waypoint = 0;
        interpState->curFrame = 0;
        interpState->duration = 1;
        if (camFov != NULL) {
            *camFov = miscCmd->fov;
        }
        if (camRoll != NULL) {
            *camRoll = CAM_DEG_TO_BINANG(miscCmd->roll);
        }
    }

    if (camPos != NULL) {
        camPos->x = pointCmd->pos.x;
        camPos->y = pointCmd->pos.y;
        camPos->z = pointCmd->pos.z;
    }

    interpState->curFrame++;

    if (interpState->curFrame >= pointCmd->duration) {
        
        interpState->type = CS_CAM_INTERP_OFF;
        return 1;
    }

    return 0;
}
