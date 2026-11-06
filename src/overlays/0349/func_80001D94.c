// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_water_effect.h"

void ref_func_80A5A534(Actor* thisx, PlayState* play) {
    EnWaterEffect* this = (EnWaterEffect*)thisx;
    s32 i;

    if (this->unk_E38 < 1.0f) {
        Actor_Kill(&this->actor);
    }

    this->unk_DC4++;

    if (this->unk_DC4 >= 0) {
        for (i = 1; i < 4; i++) {
            this->unk_DC8[i].z += this->unk_E08[i];
            this->unk_E08[i] += this->unk_E18[i];
            if (this->unk_DC8[i].z <= 0.0f) {
                this->unk_DC8[i].z = 0.0f;
                this->unk_E08[i] = 0.0f;
            }
        }

        Math_ApproachF(&this->unk_DC8[1].y, 20.0f, 1.0f, 0.025f);
        Math_ApproachF(&this->unk_DC8[2].y, 20.0f, 1.0f, 0.075f);
        Math_ApproachF(&this->unk_DC8[3].y, 20.0f, 1.0f, 0.1f);

        if (this->unk_DC4 >= 24) {
            Math_ApproachF(&this->unk_DC8[4].y, 2.0f, 0.1f, 0.2f);
            Math_ApproachZeroF(&this->unk_E2C, 1.0f, 26.0f);
            Math_ApproachZeroF(&this->unk_E30, 1.0f, 26.0f);
            Math_ApproachZeroF(&this->unk_E34, 1.0f, 24.0f);
            if (this->unk_DC4 >= 50) {
                Math_ApproachZeroF(&this->unk_E38, 1.0f, 3.75f);
            }
        }
    }
}
