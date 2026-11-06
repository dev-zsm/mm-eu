// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_demo_syoten.h"

void ref_func_80C168D0(DemoSyoten* this, PlayState* play) {
    s32 pad;
    Path* path = this->path;
    Vec3s* points;
    Vec3f worldPos;
    Vec3f projectedPos;
    f32 invW;

    if (path != NULL) {
        points = Lib_SegmentedToVirtual(this->path->points);
        points += this->unk_3EC;
        Math_Vec3s_ToVec3f(&worldPos, points);
        Actor_GetProjectedPos(play, &worldPos, &projectedPos, &invW);
        Math_Vec3f_Copy(&worldPos, &this->actor.projectedPos);
        worldPos.z = worldPos.y;
        projectedPos.z = projectedPos.y;
        this->actor.shape.rot.z = -Math_Vec3f_Yaw(&projectedPos, &worldPos);
    }
}
