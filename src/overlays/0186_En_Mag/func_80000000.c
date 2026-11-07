// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_mag.h"

void EnMag_Init(Actor* thisx, PlayState* play) {
    EnMag* this = (EnMag*)thisx;
    u16 i;

    this->unk11F54 = 6;
    this->unk11F56 = 10;

    for (i = 0; i < 6; i++) {
        this->effectScrollSs[i] = 0;
        this->effectScrollTs[i] = 0;
    }

    this->appearEffectPrimColor[0] = 255;
    this->appearEffectPrimColor[1] = 155;
    this->appearEffectPrimColor[2] = 255;
    this->appearEffectEnvColor[0] = 0;
    this->appearEffectEnvColor[1] = 255;
    this->appearEffectEnvColor[2] = 155;
    this->appearEffectPrimLodFrac = 20;
    this->appearEffectAlpha = 0;

    this->displayEffectPrimColor[0] = 255;
    this->displayEffectPrimColor[1] = 155;
    this->displayEffectPrimColor[2] = 255;
    this->displayEffectEnvColor[0] = 0;
    this->displayEffectEnvColor[1] = 255;
    this->displayEffectEnvColor[2] = 155;
    this->displayEffectPrimLodFrac = 55;
    this->displayEffectAlpha = 0;

    this->majorasMaskAlpha = 0;
    this->majorasMaskEnvColor[0] = this->majorasMaskEnvColor[1] = this->majorasMaskEnvColor[2] = 255;

    this->mainTitleAlpha = this->subtitleAlpha = this->unk11F32 = this->copyrightAlpha = 0;

    this->unk11F02 = 30;
    this->unk11F00 = this->state = MAG_STATE_INITIAL;

    if (gSaveContext.hudVisibilityForceButtonAlphasByStatus) {
        this->mainTitleAlpha = 210;
        this->unk11F32 = 255;
        this->copyrightAlpha = 255;

        this->appearEffectPrimLodFrac = 100;
        this->appearEffectAlpha = 255;
        this->appearEffectPrimColor[0] = 255;
        this->appearEffectPrimColor[1] = 255;
        this->appearEffectPrimColor[2] = 255;
        this->appearEffectEnvColor[0] = 0;
        this->appearEffectEnvColor[1] = 255;
        this->appearEffectEnvColor[2] = 155;

        this->displayEffectPrimLodFrac = 100;
        this->displayEffectAlpha = 255;
        this->displayEffectPrimColor[0] = 255;
        this->displayEffectPrimColor[1] = 255;
        this->displayEffectPrimColor[2] = 255;
        this->displayEffectEnvColor[0] = 0;
        this->displayEffectEnvColor[1] = 255;
        this->displayEffectEnvColor[2] = 155;

        gSaveContext.hudVisibilityForceButtonAlphasByStatus = false;
        this->state = MAG_STATE_FADE_IN_MASK;
        sInputDelayTimer = 20;
        gSaveContext.transFadeDuration = 1;
        gSaveContext.transWipeSpeed = 255;
    }

    Font_LoadOrderedFont(&this->font);

    this->unk11F58 = 0;
    this->unk11F5A = 0;
    this->unk11F5C = 0;
    this->unk11F60 = 0;

    this->majorasMaskEffectsFadeInTimer = 25;
    this->majorasMaskFadeInTimer = 25;
    this->mainTitleAlphaFadeInTimer = 20;
    this->effectAlphaFadeInTimer = 40;
    this->subtitleFadeInTimer = 10;
    this->copyrightFadeInTimer = 10;
    this->fadeOutTimer = 15;

    sZeldaEffectColorTimer = 30;
    sZeldaEffectColorTargetIndex = 0;
}
