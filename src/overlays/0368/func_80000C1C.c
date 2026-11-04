// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_mine.h"

void ObjMine_Water_SetWorld(ObjMine* this) {
    s32 pad; 
    ObjMineWaterChain* waterChain = &this->chain.water;
    s32 linkCount = OBJMINE_GET_LINK_COUNT(&this->actor);

    if (linkCount == 0) {
        this->actor.world.pos.y = this->actor.home.pos.y + LINK_SIZE + ATTACH_OFFSET;
    } else {
        ObjMineWaterLink* lastLink = &waterChain->links[linkCount - 1];
        Vec3f mineOffset;

        Math_Vec3f_ScaleAndStore(&lastLink->basis.y, ATTACH_OFFSET, &mineOffset);
        Math_Vec3f_Sum(&lastLink->pos, &mineOffset, &this->actor.world.pos);
    }
}
