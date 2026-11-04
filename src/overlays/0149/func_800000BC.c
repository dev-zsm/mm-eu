// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_tubo_trap.h"

void EnTuboTrap_DropCollectible(EnTuboTrap* this, PlayState* play) {
    s32 itemParam = ((this->actor.params >> 8) & 0x3F);
    s32 dropItem00Id = ref_func_800A8150(itemParam);

    if (dropItem00Id > ITEM00_NO_DROP) {
        Item_DropCollectible(play, &this->actor.world.pos, ((this->actor.params & 0x7F) << 8) | dropItem00Id);
    }
}
