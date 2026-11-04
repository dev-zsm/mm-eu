// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_quake.h"

void Quake_UpdateShakeInfo(QuakeRequest* req, ShakeInfo* shake, f32 yOffset, f32 xOffset) {
    Vec3f* at = &req->camera->at;
    Vec3f* eye = &req->camera->eye;
    Vec3f atEyeOffset;
    VecSph geo;
    VecSph eyeToAtGeo;

    if (req->isRelativeToScreen) {
        atEyeOffset.x = 0;
        atEyeOffset.y = 0;
        atEyeOffset.z = 0;
        eyeToAtGeo = OLib_Vec3fDiffToVecGeo(eye, at);

        
        geo.r = req->y * yOffset;
        
        geo.pitch = eyeToAtGeo.pitch + req->orientation.x + 0x4000;
        geo.yaw = eyeToAtGeo.yaw + req->orientation.y;
        
        atEyeOffset = OLib_AddVecGeoToVec3f(&atEyeOffset, &geo);

        
        geo.r = req->x * xOffset;
        
        geo.pitch = eyeToAtGeo.pitch + req->orientation.x;
        geo.yaw = eyeToAtGeo.yaw + req->orientation.y + 0x4000;
        
        atEyeOffset = OLib_AddVecGeoToVec3f(&atEyeOffset, &geo);
    } else {
        atEyeOffset.x = 0;
        atEyeOffset.y = req->y * yOffset;
        atEyeOffset.z = 0;

        geo.r = req->x * xOffset;
        geo.pitch = req->orientation.x;
        geo.yaw = req->orientation.y;

        atEyeOffset = OLib_AddVecGeoToVec3f(&atEyeOffset, &geo);
    }

    shake->atOffset = shake->eyeOffset = atEyeOffset;
    shake->upRollOffset = req->upRollOffset * yOffset;
    shake->fovOffset = req->fov * yOffset;
}
