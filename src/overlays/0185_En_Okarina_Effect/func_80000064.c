// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_okarina_effect.h"

void ref_func_8096B104(EnOkarinaEffect* this, PlayState* play) {
    this->timer = 80;
    play->envCtx.precipitation[PRECIP_SOS_MAX] = 60;
    gLightningStrike.delayTimer = 501.0f;
    play->envCtx.lightningState = LIGHTNING_LAST;
    Environment_PlayStormNatureAmbience(play);
    EnOkarinaEffect_SetupAction(this, ref_func_8096B174);
}
