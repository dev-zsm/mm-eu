// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_rr.h"

void ref_func_808FA6B8(EnRr* this) {
    s32 i;

    this->unk_1E1 = 0;
    if (this->actor.colChkInfo.damageEffect == 5) {
        this->unk_1EC = 80;
    } else {
        this->unk_1EC = 40;
    }
    Actor_SetColorFilter(&this->actor, COLORFILTER_COLORFLAG_RED, 255, COLORFILTER_BUFFLAG_OPA, this->unk_1EC);

    this->unk_1E6 = 20;
    this->unk_1F6 = 2500;
    this->unk_210 = 0.0f;
    this->unk_204 = 0.0f;
    this->unk_20C = 0.0f;

    for (i = 0; i < ARRAY_COUNT(this->unk_324); i++) {
        this->unk_324[i].unk_04 = 0.0f;
        this->unk_324[i].unk_0C = 1.0f;
        this->unk_324[i].unk_14 = 0;
        this->unk_324[i].unk_18 = 0;
    }

    this->actionFunc = ref_func_808FB398;
    Actor_PlaySfx(&this->actor, NA_SE_EN_LIKE_DAMAGE);
}
