// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_f40_block.h"

s32 ref_func_80BC3980(BgF40Block* this, PlayState* play) {
    Vec3s* points;

    this->unk_160 = 0;
    this->unk_164 = 0;

    if (BGF40BLOCK_GET_PATH_INDEX(&this->dyna.actor) != BGF40BLOCK_PATH_INDEX_NONE) {
        this->path = &play->setupPathList[BGF40BLOCK_GET_PATH_INDEX(&this->dyna.actor)];
        if (this->path != NULL) {
            points = Lib_SegmentedToVirtual(this->path->points);

            this->dyna.actor.world.pos.x = points->x;
            this->dyna.actor.world.pos.y = points->y;
            this->dyna.actor.world.pos.z = points->z;
        }
    } else {
        this->path = NULL;
    }

    return false;
}
