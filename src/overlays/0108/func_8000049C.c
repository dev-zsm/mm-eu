// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_demo_effect.h"

void func_8000049C(DemoEffect* this, PlayState* play) {
    s32 type = DEMO_EFFECT_GET_TYPE(&this->actor);
    f32 scale;
    f32 alphaScale;

    this->timer++;
    if (this->timer <= 100) {
        alphaScale = (100 - this->timer) * 0.01f;
        scale = alphaScale * 0.14f;

        switch (type) {
            case DEMO_EFFECT_TIMEWARP_TIMEBLOCK_LARGE:
                scale *= 1.2f;
                break;

            case DEMO_EFFECT_TIMEWARP_TIMEBLOCK_SMALL:
                scale *= 0.6f;
                break;

            case DEMO_EFFECT_TIMEWARP_LIGHTBLOCK_LARGE:
                scale *= 1.2f;
                break;

            case DEMO_EFFECT_TIMEWARP_LIGHTBLOCK_VERY_LARGE:
                scale *= 2.0f;
                break;

            default:
                break;
        }

        this->actor.scale.x = scale;
        this->actor.scale.z = scale;
        DemoEffect_SetPerVertexAlpha(alphaScale);
        Actor_PlaySfx_FlaggedCentered2(&this->actor, NA_SE_EV_TIMETRIP_LIGHT - SFX_FLAG);
    } else {
        DemoEffect_SetPerVertexAlpha(1.0f);
        Actor_Kill(&this->actor);
    }
}
