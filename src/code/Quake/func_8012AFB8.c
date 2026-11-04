// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_quake.h"

s16 Quake_Update(Camera* camera, ShakeInfo* camShake) {
    f32 absSpeedDiv;
    ShakeInfo shake;
    QuakeRequest* req;
    f32 maxCurr;
    f32 maxNext;
    s32 index;
    s32 numQuakesApplied;
    u32 isDifferentCamId;
    Vec3f zeroVec;
    PlayState* play = camera->play;

    zeroVec.x = 0.0f;
    zeroVec.y = 0.0f;
    zeroVec.z = 0.0f;

    camShake->atOffset.x = 0.0f;
    camShake->atOffset.y = 0.0f;
    camShake->atOffset.z = 0.0f;

    camShake->eyeOffset.x = 0.0f;
    camShake->eyeOffset.y = 0.0f;
    camShake->eyeOffset.z = 0.0f;

    camShake->upRollOffset = 0;
    camShake->fovOffset = 0;
    camShake->maxOffset = 0.0f;

    if (sQuakeRequestCount == 0) {
        return 0;
    }

    numQuakesApplied = 0;
    for (index = 0; index < ARRAY_COUNT(sQuakeRequests); index++) {
        req = &sQuakeRequests[index];
        if (req->type == QUAKE_TYPE_NONE) {
            continue;
        }

        if (play->cameraPtrs[req->camId] == NULL) {
            Quake_Remove(req);
            continue;
        }

        isDifferentCamId = (camera->camId != req->camera->camId);
        absSpeedDiv = (f32)ABS(req->speed) / 0x8000;
        if (sQuakeCallbacks[req->type](req, &shake) == 0) {
            
            Quake_Remove(req);
            continue;
        }

        if (isDifferentCamId) {
            
            continue;
        }

        if (fabsf(camShake->atOffset.x) < fabsf(shake.atOffset.x)) {
            camShake->atOffset.x = shake.atOffset.x;
        }
        if (fabsf(camShake->atOffset.y) < fabsf(shake.atOffset.y)) {
            camShake->atOffset.y = shake.atOffset.y;
        }
        if (fabsf(camShake->atOffset.z) < fabsf(shake.atOffset.z)) {
            camShake->atOffset.z = shake.atOffset.z;
        }
        if (fabsf(camShake->eyeOffset.x) < fabsf(shake.eyeOffset.x)) {
            camShake->eyeOffset.x = shake.eyeOffset.x;
        }
        if (fabsf(camShake->eyeOffset.y) < fabsf(shake.eyeOffset.y)) {
            camShake->eyeOffset.y = shake.eyeOffset.y;
        }
        if (fabsf(camShake->eyeOffset.z) < fabsf(shake.eyeOffset.z)) {
            camShake->eyeOffset.z = shake.eyeOffset.z;
        }
        if (camShake->upRollOffset < shake.upRollOffset) {
            camShake->upRollOffset = shake.upRollOffset;
        }
        if (camShake->fovOffset < shake.fovOffset) {
            camShake->fovOffset = shake.fovOffset;
        }

        maxCurr = OLib_Vec3fDist(&shake.atOffset, &zeroVec) * absSpeedDiv;
        maxNext = OLib_Vec3fDist(&shake.eyeOffset, &zeroVec) * absSpeedDiv;
        maxCurr = CLAMP_MIN(maxCurr, maxNext);

        maxNext = (camShake->upRollOffset * (7.0f / 2500.0f)) * absSpeedDiv;
        maxCurr = CLAMP_MIN(maxCurr, maxNext);

        maxNext = (camShake->fovOffset * (7.0f / 2500.0f)) * absSpeedDiv;
        maxCurr = CLAMP_MIN(maxCurr, maxNext);

        if (camShake->maxOffset < maxCurr) {
            camShake->maxOffset = maxCurr;
        }

        numQuakesApplied++;
    }
    return numQuakesApplied;
}
