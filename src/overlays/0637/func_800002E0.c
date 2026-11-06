// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_demo_syoten.h"

void ref_func_80C16760(DemoSyoten* this, PlayState* play) {
    s32 pad;
    Vec3s* points;
    Vec3f sp2C;

    this->unk_3EC = 0;
    if (DEMOSYOTEN_GET_PATH_INDEX(&this->actor) != DEMOSYOTEN_PATH_INDEX_NONE) {
        this->path = &play->setupPathList[DEMOSYOTEN_GET_PATH_INDEX(&this->actor)];
        if (this->path != NULL) {
            points = Lib_SegmentedToVirtual(this->path->points);
            Math_Vec3s_ToVec3f(&this->actor.world.pos, &points[0]);
            this->unk_3EC++;
            points++;
            Math_Vec3s_ToVec3f(&sp2C, points);
            this->actor.world.rot.y = Math_Vec3f_Yaw(&this->actor.world.pos, &sp2C);
            this->actor.world.rot.x = Math_Vec3f_Pitch(&this->actor.world.pos, &sp2C);
        }
    } else {
        this->path = NULL;
    }
}
