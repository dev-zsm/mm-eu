// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_icefloe.h"

void ref_func_80AC4C34(BgIcefloe* this, PlayState* play) {
    WaterBox* waterBox;

    this->timer--;
    if ((this->timer == 0) ||
        !BgCheck_GetWaterSurfaceNoBgId(play, &play->colCtx, this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.z,
                                       &this->dyna.actor.home.pos.y, &waterBox)) {
        ref_func_80AC4CF0(this);
    } else {
        this->dyna.actor.world.pos.y =
            (Math_SinF(this->timer * (M_PIf / 30)) * 3.0f) + (this->dyna.actor.home.pos.y + 10.0f);
    }
}
