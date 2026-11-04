// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_mine.h"

void ObjMine_Air_CheckAC(ObjMine* this, s16* hitAngle, s16* torqueAngle) {
    s32 pad[2];
    Vec3s* centerPos3s = &this->collider.elements[0].dim.worldSphere.center;
    Vec3f centerPos;
    s16 yawToAttack;
    Actor* attackActor = this->collider.base.ac;

    Math_Vec3s_ToVec3f(&centerPos, centerPos3s);
    yawToAttack = Math_Vec3f_Yaw(&attackActor->world.pos, &centerPos);

    
    if (this->collider.elements[0].base.acHitElem->atDmgInfo.dmgFlags & 0x13820) {
        *hitAngle = attackActor->shape.rot.y;
        *torqueAngle = attackActor->shape.rot.y - yawToAttack;
    } else {
        Vec3f hitPos;
        Vec3s* hitPos3s = &this->collider.elements[0].base.acDmgInfo.hitPos;

        Math_Vec3s_ToVec3f(&hitPos, hitPos3s);
        *hitAngle = Actor_WorldYawTowardActor(attackActor, &this->actor);
        *torqueAngle = Math_Vec3f_Yaw(&attackActor->world.pos, &hitPos) - yawToAttack;
    }
}
