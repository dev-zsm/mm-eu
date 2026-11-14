// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_demo_effect.h"

void func_800005AC(DemoEffect* this, PlayState* play) {
    Actor_PlaySfx_FlaggedCentered2(&this->actor, NA_SE_EV_TIMETRIP_LIGHT - SFX_FLAG);

    if (SkelCurve_Update(play, &this->skelCurve)) {
        SkelCurve_SetAnim(&this->skelCurve, &gTimewarpAnim, 1.0f, 60.0f, 59.0f, 0.0f);
        this->actionFunc = DemoEffect_FinishTimewarp;
        this->timer = 0;
    }
}
