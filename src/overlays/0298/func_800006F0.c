// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_numa_hana.h"

void BgNumaHana_UnfoldOuterPetals(BgNumaHana* this, PlayState* play) {
    Math_StepToS(&this->outerPetalAngularVelocityZ, 240, 14);
    if (Math_ScaledStepToS(&this->outerPetalRotZ, -0x4000, this->outerPetalAngularVelocityZ)) {
        if (this->transitionTimer >= 11) {
            BgNumaHana_SetupRaiseFlower(this);
        } else {
            if (this->transitionTimer <= 0) {
                this->settleRotZ = 0;
                this->settleAngle = 0x5120;
                this->settleScale = 130.0f;
                Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_FLOWERPETAL_STOP);
            }
            this->transitionTimer++;
        }
    } else {
        Actor_PlaySfx_Flagged(&this->dyna.actor, NA_SE_EV_FLOWERPETAL_MOVE - SFX_FLAG);
    }

    BgNumaHana_UpdateSettleRotation(&this->settleRotZ, &this->settleAngle, &this->settleScale, 7.0f);
    this->petalRotZ = this->innerPetalRotZ + this->settleRotZ;
    BgNumaHana_UpdatePetalPosRots(this);
}
