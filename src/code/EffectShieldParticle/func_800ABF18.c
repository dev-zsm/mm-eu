// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_shield_particle.h"

void EffectShieldParticle_GetColors(EffectShieldParticle* this, Color_RGBA8* primColor, Color_RGBA8* envColor) {
    s32 halfDuration = this->duration * 0.5f;

    if (halfDuration == 0) {
        primColor->r = this->primColorStart.r;
        primColor->g = this->primColorStart.g;
        primColor->b = this->primColorStart.b;
        primColor->a = this->primColorStart.a;
        envColor->r = this->envColorStart.r;
        envColor->g = this->envColorStart.g;
        envColor->b = this->envColorStart.b;
        envColor->a = this->envColorStart.a;
    } else if (this->timer < halfDuration) {
        f32 ratio = this->timer / (f32)halfDuration;

        primColor->r = LERPIMP(this->primColorStart.r, this->primColorMid.r, ratio);
        primColor->g = LERPIMP(this->primColorStart.g, this->primColorMid.g, ratio);
        primColor->b = LERPIMP(this->primColorStart.b, this->primColorMid.b, ratio);
        primColor->a = LERPIMP(this->primColorStart.a, this->primColorMid.a, ratio);
        envColor->r = LERPIMP(this->envColorStart.r, this->envColorMid.r, ratio);
        envColor->g = LERPIMP(this->envColorStart.g, this->envColorMid.g, ratio);
        envColor->b = LERPIMP(this->envColorStart.b, this->envColorMid.b, ratio);
        envColor->a = LERPIMP(this->envColorStart.a, this->envColorMid.a, ratio);
    } else {
        f32 ratio = (this->timer - halfDuration) / (f32)halfDuration;

        primColor->r = LERPIMP(this->primColorMid.r, this->primColorEnd.r, ratio);
        primColor->g = LERPIMP(this->primColorMid.g, this->primColorEnd.g, ratio);
        primColor->b = LERPIMP(this->primColorMid.b, this->primColorEnd.b, ratio);
        primColor->a = LERPIMP(this->primColorMid.a, this->primColorEnd.a, ratio);
        envColor->r = LERPIMP(this->envColorMid.r, this->envColorEnd.r, ratio);
        envColor->g = LERPIMP(this->envColorMid.g, this->envColorEnd.g, ratio);
        envColor->b = LERPIMP(this->envColorMid.b, this->envColorEnd.b, ratio);
        envColor->a = LERPIMP(this->envColorMid.a, this->envColorEnd.a, ratio);
    }
}
