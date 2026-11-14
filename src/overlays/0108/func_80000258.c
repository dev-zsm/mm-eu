// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_demo_effect.h"

void func_80000258(DemoEffect* this, PlayState* play) {
    s32 type = DEMO_EFFECT_GET_TYPE(&this->actor);

    if (SkelCurve_Init(play, &this->skelCurve, &gTimewarpSkel, &gTimewarpAnim)) {}

    SkelCurve_SetAnim(&this->skelCurve, &gTimewarpAnim, 1.0f, 59.0f, 1.0f, 1.7f);
    SkelCurve_Update(play, &this->skelCurve);
    this->actionFunc = DemoEffect_StartTimewarp;

    switch (type) {
        case DEMO_EFFECT_TIMEWARP_TIMEBLOCK_LARGE:
            Actor_SetScale(&this->actor, 168.0f * 0.001f);
            break;

        case DEMO_EFFECT_TIMEWARP_TIMEBLOCK_SMALL:
            Actor_SetScale(&this->actor, 84.0f * 0.001f);
            break;

        case DEMO_EFFECT_TIMEWARP_LIGHTBLOCK_LARGE:
            Actor_SetScale(&this->actor, 168.0f * 0.001f);
            break;

        case DEMO_EFFECT_TIMEWARP_LIGHTBLOCK_VERY_LARGE:
            Actor_SetScale(&this->actor, 280.0f * 0.001f);
            break;

        default:
            Actor_SetScale(&this->actor, 14.0f * 0.001f);
            break;
    }
}
