// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_dust.h"

void EffDust_Init(Actor* thisx, PlayState* play) {
    EffDust* this = (EffDust*)thisx;
    u32 type = this->actor.params;

    ref_func_80918B40(this);
    switch (type) {
        case EFF_DUST_TYPE_0:
            this->actionFunc = ref_func_80918D64;
            this->actor.draw = ref_func_80919768;
            this->dx = 1.0f;
            this->dy = 1.0f;
            this->dz = 1.0f;
            this->scalingFactor = 0.2f;
            break;

        case EFF_DUST_TYPE_1:
            this->actionFunc = ref_func_80918FE4;
            this->actor.draw = ref_func_80919768;
            this->dy = 1.0f;
            this->dx = 0.8f;
            this->dz = 0.8f;
            this->scalingFactor = 0.5f;
            break;

        case EFF_DUST_TYPE_SPIN_ATTACK_CHARGE:
        case EFF_DUST_TYPE_3:
            this->actionFunc = ref_func_80919230;
            this->actor.draw = ref_func_809199FC;
            this->actor.room = -1;
            this->dx = 0.5f;
            this->scalingFactor = 15.0f;
            break;

        case EFF_DUST_TYPE_4:
            this->actionFunc = ref_func_80919230;
            this->actor.draw = ref_func_809199FC;
            this->actor.room = -1;
            this->dx = 0.5f;
            this->scalingFactor = 10.0f;
            break;

        case EFF_DUST_TYPE_5:
            this->actionFunc = ref_func_80919230;
            this->actor.draw = ref_func_809199FC;
            this->actor.room = -1;
            this->dx = 0.5f;
            this->scalingFactor = 20.0f;
            break;

        default:
            free(this);
            break;
    }
    this->life = 10;
}
