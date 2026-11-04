// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_mag.h"

void EnMag_UpdateDisplayEffectColors(Actor* thisx) {
    static s16 sDisplayEffectPrimRedTargets[] = { 155, 255 };
    static s16 sDisplayEffectPrimGreenTargets[] = { 255, 155 };
    static s16 sDisplayEffectPrimBlueTargets[] = { 55, 255 };
    static s16 sDisplayEffectEnvRedTargets[] = { 255, 0 };
    static s16 sDisplayEffectEnvBlueTargets[] = { 255, 155 };
    EnMag* this = (EnMag*)thisx;
    s16 colorStep;

    TIMED_STEP_TO(this->displayEffectPrimColor[0], sDisplayEffectPrimRedTargets[sZeldaEffectColorTargetIndex],
                  sZeldaEffectColorTimer, colorStep);
    TIMED_STEP_TO(this->displayEffectPrimColor[1], sDisplayEffectPrimGreenTargets[sZeldaEffectColorTargetIndex],
                  sZeldaEffectColorTimer, colorStep);
    TIMED_STEP_TO(this->displayEffectPrimColor[2], sDisplayEffectPrimBlueTargets[sZeldaEffectColorTargetIndex],
                  sZeldaEffectColorTimer, colorStep);
    TIMED_STEP_TO(this->displayEffectEnvColor[0], sDisplayEffectEnvRedTargets[sZeldaEffectColorTargetIndex],
                  sZeldaEffectColorTimer, colorStep);
    
    TIMED_STEP_TO(this->displayEffectEnvColor[2], sDisplayEffectEnvBlueTargets[sZeldaEffectColorTargetIndex],
                  sZeldaEffectColorTimer, colorStep);

    sZeldaEffectColorTimer--;
    if (sZeldaEffectColorTimer == 0) {
        this->displayEffectPrimColor[0] = sDisplayEffectPrimRedTargets[sZeldaEffectColorTargetIndex];
        this->displayEffectPrimColor[1] = sDisplayEffectPrimGreenTargets[sZeldaEffectColorTargetIndex];
        this->displayEffectPrimColor[2] = sDisplayEffectPrimBlueTargets[sZeldaEffectColorTargetIndex];
        this->displayEffectEnvColor[0] = sDisplayEffectEnvRedTargets[sZeldaEffectColorTargetIndex];
        
        this->displayEffectEnvColor[2] = sDisplayEffectEnvBlueTargets[sZeldaEffectColorTargetIndex];
        sZeldaEffectColorTimer = 30;
        sZeldaEffectColorTargetIndex ^= 1;
    }
}
