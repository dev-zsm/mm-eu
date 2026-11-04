// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_fu_kaiten.h"

void BgFuKaiten_UpdateHeight(BgFuKaiten* this) {
    this->bounce += this->bounceSpeed;
    this->dyna.actor.world.pos.y = this->dyna.actor.home.pos.y + this->elevation + this->bounceHeight;

    this->dyna.actor.world.pos.y -= this->bounceHeight * Math_CosS(this->bounce);
}
