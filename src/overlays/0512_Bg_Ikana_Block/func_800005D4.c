// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_block.h"

void ref_func_80B7F034(BgIkanaBlock* this, PlayState* play) {
    if (this->unk_17D > 0) {
        this->unk_17D--;
    }

    if (ref_func_80B7EEB4(this, play)) {
        DynaPoly_EnableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
        this->dyna.actor.draw = ref_func_80B7F564;
        ref_func_80B7F0A4(this);
    }
}
