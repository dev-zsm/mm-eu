// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_block.h"

s32 ref_func_80B7EEB4(BgIkanaBlock* this, PlayState* play) {
    ref_func_80B7EDC4(this, play);

    if (this->dyna.actor.floorHeight > (BGCHECK_Y_MIN + 1.0f)) {
        if (DynaPoly_GetActor(&play->colCtx, this->dyna.actor.floorBgId)) {
            this->dyna.actor.world.pos.y = this->dyna.actor.floorHeight - this->unk_170;
            return true;
        }
    }
    return false;
}
