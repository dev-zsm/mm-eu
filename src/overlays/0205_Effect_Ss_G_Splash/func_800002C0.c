// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_ss_g_splash.h"

void EffectSsGSplash_Update(PlayState* play, u32 index, EffectSs* this) {
    Vec3f newSplashPos;

    if ((this->rType == EFFSSGSPLASH_TYPE_1) && (this->life == 5)) {
        newSplashPos = this->pos;
        newSplashPos.y += ((this->rgScale * 20) * 0.002f);
        EffectSsGSplash_Spawn(play, &newSplashPos, 0, 0, 2, this->rgScale / 2);
    }

    this->rgTexIndex += this->rgTexIndexStep;
}
