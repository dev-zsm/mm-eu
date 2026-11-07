// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_m_thunder.h"

void ref_func_808B5EEC(EnMThunder* this, PlayState* play) {
    if (this->timer < 2) {
        if (this->chargingAlpha < 40) {
            this->chargingAlpha = 0;
        } else {
            this->chargingAlpha -= 40;
        }
    }

    this->scroll += 2.0f * this->alphaFrac;

    if (this->adjustLightsArg1 < this->lightColorFrac) {
        this->adjustLightsArg1 = F32_LERPIMP(this->adjustLightsArg1, this->lightColorFrac, 0.1f);
    } else {
        this->adjustLightsArg1 = this->lightColorFrac;
    }
}
