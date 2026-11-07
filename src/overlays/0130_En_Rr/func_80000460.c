// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_rr.h"

void ref_func_808FA260(EnRr* this) {
    static f32 ref_D_808FC1E4[] = { 0.0f, 500.0f, 750.0f, 1000.0f, 1000.0f };
    s32 i;

    this->unk_1E1 = 1;
    this->unk_1E6 = 20;
    this->unk_1F6 = 2500;
    this->unk_210 = 0.0f;

    for (i = 0; i < ARRAY_COUNT(this->unk_324); i++) {
        this->unk_324[i].unk_04 = ref_D_808FC1E4[i];
        this->unk_324[i].unk_14 = 6000;
        this->unk_324[i].unk_18 = 0;
        this->unk_324[i].unk_0C = 0.8f;
    }

    this->actionFunc = ref_func_808FB088;

    Actor_PlaySfx(&this->actor, NA_SE_EN_LIKE_UNARI);
}
