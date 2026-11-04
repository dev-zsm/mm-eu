// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/cutscene_camera.h"

u8 CutsceneCamera_ProcessSpline(CutsceneCamera* csCamera) {
    s32 sp5C;
    f32* camFov;
    s16* camRoll;
    CsCamInterpolateCallback interpHandler;
    Player* player;
    Actor* target;
    s16 numPoints;

    sp5C = true;
    if (csCamera->state == CS_CAM_STATE_DONE_SPLINE) {
        return false;
    }

    player = GET_PLAYER(csCamera->camera->play);
    target = csCamera->camera->target;

    if (csCamera->eyeCmd[csCamera->atInterp.curPoint].interpType <
        csCamera->atCmd[csCamera->eyeInterp.curPoint].interpType) {
        sp5C = false;
    }

    csCamera->eyeInterp.curPos = csCamera->camera->eye;
    csCamera->atInterp.curPos = csCamera->camera->at;

    if (sp5C) {
        camFov = NULL;
    } else {
        camFov = &csCamera->camera->fov;
    }

    if (sp5C) {
        camRoll = NULL;
    } else {
        camRoll = &csCamera->camera->roll;
    }

    interpHandler = CutsceneCamera_Interpolate(csCamera->atCmd[csCamera->eyeInterp.curPoint].interpType);

    switch (csCamera->atCmd[csCamera->eyeInterp.curPoint].relativeTo) {
        case CS_CAM_REL_2:
            OLib_Vec3fDiff(&player->actor.world, &csCamera->camera->at, &csCamera->camera->at, OLIB_DIFF);
            break;

        case CS_CAM_REL_3:
            OLib_Vec3fDiff(&player->actor.world, &csCamera->camera->at, &csCamera->camera->at, OLIB_DIFF_OFFSET);
            break;

        case CS_CAM_REL_1:
            OLib_Vec3fDiff(&player->actor.world, &csCamera->camera->at, &csCamera->camera->at, OLIB_DIFF_OFFSET);
            break;

        case CS_CAM_REL_4:
            OLib_Vec3fDiff(&target->world, &csCamera->camera->at, &csCamera->camera->at, OLIB_DIFF_OFFSET);
            break;

        case CS_CAM_REL_5:
            OLib_Vec3fDiff(&target->world, &csCamera->camera->at, &csCamera->camera->at, OLIB_DIFF);
            break;

        default: 
            break;
    }

    numPoints = interpHandler(&csCamera->camera->at, camFov, camRoll, &csCamera->atCmd[csCamera->eyeInterp.curPoint],
                              &csCamera->miscCmd[csCamera->eyeInterp.curPoint], &csCamera->eyeInterp);

    switch (csCamera->atCmd[csCamera->eyeInterp.curPoint].relativeTo) {
        case CS_CAM_REL_2:
            OLib_Vec3fAdd(&player->actor.world, &csCamera->camera->at, &csCamera->camera->at, OLIB_ADD);
            break;

        case CS_CAM_REL_3:
            OLib_Vec3fAdd(&player->actor.world, &csCamera->camera->at, &csCamera->camera->at, OLIB_ADD_OFFSET);
            csCamera->camera->at.y += ref_func_80163660(&player->actor);
            break;

        case CS_CAM_REL_1:
            OLib_Vec3fAdd(&player->actor.world, &csCamera->camera->at, &csCamera->camera->at, OLIB_ADD_OFFSET);
            break;

        case CS_CAM_REL_4:
            OLib_Vec3fAdd(&target->world, &csCamera->camera->at, &csCamera->camera->at, OLIB_ADD_OFFSET);
            break;

        case CS_CAM_REL_5:
            OLib_Vec3fAdd(&target->world, &csCamera->camera->at, &csCamera->camera->at, OLIB_ADD);
            break;

        default: 
            break;
    }

    csCamera->eyeInterp.curPoint += numPoints;

    if (sp5C) {
        camFov = &csCamera->camera->fov;
    } else {
        camFov = NULL;
    }

    if (sp5C) {
        camRoll = &csCamera->camera->roll;
    } else {
        camRoll = NULL;
    }

    interpHandler = CutsceneCamera_Interpolate(csCamera->eyeCmd[csCamera->atInterp.curPoint].interpType);

    switch (csCamera->eyeCmd[csCamera->atInterp.curPoint].relativeTo) {
        case CS_CAM_REL_2:
            OLib_Vec3fDiff(&player->actor.world, &csCamera->camera->eye, &csCamera->camera->eye, OLIB_DIFF);
            break;

        case CS_CAM_REL_3:
            OLib_Vec3fDiff(&player->actor.world, &csCamera->camera->eye, &csCamera->camera->eye, OLIB_DIFF_OFFSET);
            break;

        case CS_CAM_REL_1:
            OLib_Vec3fDiff(&player->actor.world, &csCamera->camera->eye, &csCamera->camera->eye, OLIB_DIFF_OFFSET);
            break;

        case CS_CAM_REL_4:
            OLib_Vec3fDiff(&target->world, &csCamera->camera->eye, &csCamera->camera->eye, OLIB_DIFF_OFFSET);
            break;

        case CS_CAM_REL_5:
            OLib_Vec3fDiff(&target->world, &csCamera->camera->eye, &csCamera->camera->eye, OLIB_DIFF);
            break;

        default: 
            break;
    }

    numPoints = interpHandler(&csCamera->camera->eye, camFov, camRoll, &csCamera->eyeCmd[csCamera->atInterp.curPoint],
                              &csCamera->miscCmd[csCamera->atInterp.curPoint], &csCamera->atInterp);

    switch (csCamera->eyeCmd[csCamera->atInterp.curPoint].relativeTo) {
        case CS_CAM_REL_2:
            OLib_Vec3fAdd(&player->actor.world, &csCamera->camera->eye, &csCamera->camera->eye, OLIB_ADD);
            break;

        case CS_CAM_REL_3:
            OLib_Vec3fAdd(&player->actor.world, &csCamera->camera->eye, &csCamera->camera->eye, OLIB_ADD_OFFSET);
            csCamera->camera->eye.y += ref_func_80163660(&player->actor);
            break;

        case CS_CAM_REL_1:
            OLib_Vec3fAdd(&player->actor.world, &csCamera->camera->eye, &csCamera->camera->eye, OLIB_ADD_OFFSET);
            break;

        case CS_CAM_REL_4:
            OLib_Vec3fAdd(&target->world, &csCamera->camera->eye, &csCamera->camera->eye, OLIB_ADD_OFFSET);
            break;

        case CS_CAM_REL_5:
            OLib_Vec3fAdd(&target->world, &csCamera->camera->eye, &csCamera->camera->eye, OLIB_ADD);
            break;

        default: 
            break;
    }

    csCamera->atInterp.curPoint += numPoints;

    if ((csCamera->eyeInterp.curPoint >= csCamera->eyeInterp.numEntries) ||
        (csCamera->atInterp.curPoint >= csCamera->atInterp.numEntries)) {
        return false;
    }

    return true;
}
