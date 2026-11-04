// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_play.h"

s32 Play_SetCameraAtEyeUp(PlayState* this, s16 camId, Vec3f* at, Vec3f* eye, Vec3f* up) {
    s32 successfullySet = 0;
    s16 camIdx = (camId == CAM_ID_NONE) ? this->activeCamId : camId;
    Camera* camera = this->cameraPtrs[camIdx];

    successfullySet |= Camera_SetViewParam(camera, CAM_VIEW_AT, at);
    successfullySet <<= 1;
    successfullySet |= Camera_SetViewParam(camera, CAM_VIEW_EYE, eye);
    successfullySet <<= 1;
    successfullySet |= Camera_SetViewParam(camera, CAM_VIEW_UP, up);

    camera->dist = Math3D_Vec3f_DistXYZ(at, eye);

    if (camera->focalActor != NULL) {
        camera->focalActorAtOffset.x = at->x - camera->focalActor->world.pos.x;
        camera->focalActorAtOffset.y = at->y - camera->focalActor->world.pos.y;
        camera->focalActorAtOffset.z = at->z - camera->focalActor->world.pos.z;
    } else {
        camera->focalActorAtOffset.x = camera->focalActorAtOffset.y = camera->focalActorAtOffset.z = 0.0f;
    }

    camera->atLerpStepScale = 0.01f;

    return successfullySet;
}
