// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_demo_syoten.h"

s32 ref_func_80C16818(DemoSyoten* this) {
    s32 pad;
    Path* path = this->path;
    Vec3s* points;
    Vec3f sp28;

    if (path == NULL) {
        return true;
    }

    points = Lib_SegmentedToVirtual(this->path->points);
    points += this->unk_3EC;
    Math_Vec3s_ToVec3f(&sp28, points);
    this->actor.world.rot.y = Math_Vec3f_Yaw(&this->actor.world.pos, &sp28);
    this->actor.world.rot.x = Math_Vec3f_Pitch(&this->actor.world.pos, &sp28);
    Actor_MoveWithoutGravityReverse(&this->actor);
    if (Math_Vec3f_DistXYZ(&this->actor.world.pos, &sp28) < 2.0f) {
        return true;
    }
    return false;
}
