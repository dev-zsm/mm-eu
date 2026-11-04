// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_boat.h"

s16 ObjBoat_GetNextPoint(ObjBoat* this, Vec3f* nextPoint) {
    s16 yaw;
    Vec3s* curPoint = &this->pathPoints[(s32)this->curPointIndex];

    Math_Vec3s_ToVec3f(nextPoint, &curPoint[this->direction]);
    yaw = Math_Vec3f_Yaw(&this->dyna.actor.world.pos, nextPoint);

    return ((this->direction > 0) ? yaw : yaw + 0x8000);
}
