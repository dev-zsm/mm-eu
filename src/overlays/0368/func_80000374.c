// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_mine.h"

void ObjMine_Water_CheckAC(ObjMine* this, Vec3f* knockbackDir) {
    Actor* attackActor = this->collider.base.ac;

    
    if (this->collider.elements[0].base.acHitElem->atDmgInfo.dmgFlags & 0x13820) {
        Matrix_Push();
        Matrix_RotateYS(attackActor->shape.rot.y, MTXMODE_NEW);
        Matrix_RotateXS(attackActor->shape.rot.x, MTXMODE_APPLY);
        Matrix_MultVecZ(1.0f, knockbackDir);
        Matrix_Pop();
    } else {
        Vec3f posDiff;
        Sphere16* sphere = &this->collider.elements[0].dim.worldSphere;

        posDiff.x = sphere->center.x - attackActor->world.pos.x;
        posDiff.y = sphere->center.y - attackActor->world.pos.y;
        posDiff.z = sphere->center.z - attackActor->world.pos.z;

        if (!ObjMine_GetUnitVec3f(&posDiff, knockbackDir)) {
            Math_Vec3f_Copy(knockbackDir, &sStandardBasis.y);
        }
    }
}
