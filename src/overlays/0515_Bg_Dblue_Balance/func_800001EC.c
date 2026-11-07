// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_dblue_balance.h"

void ref_func_80B8259C(BgDblueBalance* this, PlayState* play) {
    s32 pad;
    WaterBox* waterBox;
    f32 waterSurface;

    if (BgCheck_GetWaterSurfaceNoBgId(play, &play->colCtx, this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.z,
                                      &waterSurface, &waterBox)) {
        this->dyna.actor.depthInWater = waterSurface - this->dyna.actor.world.pos.y;
        this->unk_228 = waterSurface;
        if ((this->dyna.actor.depthInWater < 150.0f) && (this->dyna.actor.depthInWater > -150.0f)) {
            this->unk_182 = true;
        } else {
            this->unk_182 = false;
        }
    } else {
        this->unk_182 = false;
    }
}
