// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_mine.h"

void ObjMine_Path_Move(ObjMine* this, PlayState* play) {
    Actor* thisx = &this->actor;
    Vec3f nextWaypoint;
    f32 distToWaypoint;
    f32 step;
    f32 target;
    s32 bgId; 

    
    Math_Vec3s_ToVec3f(&nextWaypoint, &this->waypoints[this->waypointIndex + 1]);
    Math_Vec3f_Diff(&nextWaypoint, &thisx->world.pos, &thisx->velocity);
    distToWaypoint = Math3D_Vec3fMagnitude(&thisx->velocity);

    
    if ((distToWaypoint < (this->pathSpeed * 8.0f)) && (this->pathSpeed > 2.0f)) {
        target = 2.0f + ((this->pathSpeed - 2.0f) * 0.1f);
        step = this->pathSpeed * 0.03f;
    } else {
        target = this->pathSpeed;
        step = this->pathSpeed * 0.16f;
    }
    Math_StepToF(&thisx->speed, target, step);

    
    if ((thisx->speed + 0.05f) < distToWaypoint) {
        
        Math_Vec3f_Scale(&thisx->velocity, thisx->speed / distToWaypoint);
        thisx->world.pos.x += thisx->velocity.x;
        thisx->world.pos.y += thisx->velocity.y;
        thisx->world.pos.z += thisx->velocity.z;
    } else {
        thisx->speed *= 0.4f;
        this->waypointIndex++;
        if (this->waypointIndex >= this->waypointCount) {
            this->waypointIndex = 0;
        }
        ObjMine_Path_MoveToWaypoint(this, this->waypointIndex);
    }
    thisx->floorHeight = BgCheck_EntityRaycastFloor5(&play->colCtx, &thisx->floorPoly, &bgId, thisx, &thisx->world.pos);
    if (thisx->flags & ACTOR_FLAG_INSIDE_CULLING_VOLUME) {
        Vec3f rotAxis;
        Vec3f yhatCrossV;
        MtxF rotMtxF;

        
        Math3D_Vec3f_Cross(&sStandardBasis.y, &thisx->velocity, &yhatCrossV);
        if (ObjMine_GetUnitVec3f(&yhatCrossV, &rotAxis)) {
            Matrix_RotateAxisF(thisx->speed / PATH_RADIUS, &rotAxis, MTXMODE_NEW);
            Matrix_RotateYS(thisx->shape.rot.y, MTXMODE_APPLY);
            Matrix_RotateXS(thisx->shape.rot.x, MTXMODE_APPLY);
            Matrix_RotateZS(thisx->shape.rot.z, MTXMODE_APPLY);
            Matrix_Get(&rotMtxF);
            Matrix_MtxFToYXZRot(&rotMtxF, &thisx->shape.rot, false);
        }
    }
}
