// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_kibako2.h"

void ObjKibako2_SpawnCollectible(ObjKibako2* this, PlayState* play) {
    s32 dropItem00Id = ref_func_800A8150(KIBAKO2_COLLECTIBLE_ID(&this->dyna.actor));

    if (dropItem00Id > ITEM00_NO_DROP) {
        Item_DropCollectible(play, &this->dyna.actor.world.pos,
                             dropItem00Id | KIBAKO2_COLLECTIBLE_FLAG(&this->dyna.actor) << 8);
    }
}
