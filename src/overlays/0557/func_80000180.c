// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_f40_block.h"

s32 ref_func_80BC3B00(BgF40Block* this) {
    s32 pad;
    Path* path;
    Vec3s* points;
    Vec3f sp28;
    Vec3f sp24;

    if (this->path == NULL) {
        return true;
    }

    if (this->unk_160 == this->unk_164) {
        return true;
    }

    path = this->path;
    points = Lib_SegmentedToVirtual(path->points);
    points += this->unk_164;

    sp28.x = points->x;
    sp28.y = points->y;
    sp28.z = points->z;

    if (this->unk_168 == 6) {
        sp24.x = sp28.x - this->dyna.actor.world.pos.x;
        sp24.y = sp28.y - this->dyna.actor.world.pos.y;
        sp24.z = sp28.z - this->dyna.actor.world.pos.z;

        if (sp24.x > 10.0f) {
            this->unk_168 = 0;
        }

        if (sp24.y > 10.0f) {
            this->unk_168 = 1;
        }

        if (sp24.z > 10.0f) {
            this->unk_168 = 2;
        }

        if (sp24.x < -10.0f) {
            this->unk_168 = 3;
        }

        if (sp24.y < -10.0f) {
            this->unk_168 = 4;
        }

        if (sp24.z < -10.0f) {
            this->unk_168 = 5;
        }
    }

    if (Math_Vec3f_StepTo(&this->dyna.actor.world.pos, &sp28, this->dyna.actor.speed) <= 0.0f) {
        this->unk_168 = 6;
        this->unk_160 = this->unk_164;
        return true;
    }
    return false;
}
