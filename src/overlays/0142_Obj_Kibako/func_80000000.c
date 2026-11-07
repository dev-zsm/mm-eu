// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_kibako.h"

void ObjKibako_SpawnCollectible(ObjKibako* this, PlayState* play) {
    s32 dropItem00Id;

    if (this->isDropCollected == 0) {
        dropItem00Id = ref_func_800A8150(KIBAKO_COLLECTIBLE_ID(&this->actor));
        if (dropItem00Id > ITEM00_NO_DROP) {
            Item_DropCollectible(play, &this->actor.world.pos,
                                 dropItem00Id | KIBAKO_COLLECTIBLE_FLAG(&this->actor) << 8);
            this->isDropCollected = 1;
        }
    }
}
