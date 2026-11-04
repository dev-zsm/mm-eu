// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_g_spk.h"

void EffectSsGSpk_UpdateNoAccel(PlayState* play, u32 index, EffectSs* this) {
    if (this->actor != NULL) {
        if ((this->actor->category == ACTORCAT_EXPLOSIVES) && (this->actor->update != NULL)) {
            this->pos.x += (Math_SinS(this->actor->world.rot.y) * this->actor->speed);
            this->pos.z += (Math_CosS(this->actor->world.rot.y) * this->actor->speed);
        }
    }

    this->rTexIndex++;
    this->rTexIndex &= 3;
    this->rScale += this->rScaleStep;
}
