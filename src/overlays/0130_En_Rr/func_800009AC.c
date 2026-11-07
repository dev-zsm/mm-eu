// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_rr.h"

void ref_func_808FA7AC(EnRr* this) {
    static f32 ref_D_808FC1F8[] = { 0.0f, 500.0f, 750.0f, 1000.0f, 1000.0f, 0.0f };
    s32 i;

    this->unk_1F6 = 2500;
    this->unk_1E1 = 1;
    this->unk_1E6 = 10;
    this->unk_210 = 0.0f;

    for (i = 0; i < ARRAY_COUNT(this->unk_324); i++) {
        this->unk_324[i].unk_04 = ref_D_808FC1F8[i];
        this->unk_324[i].unk_0C = 0.8f;
        this->unk_324[i].unk_14 = 5000;
        this->unk_324[i].unk_18 = 0;
    }

    this->actionFunc = ref_func_808FB2C0;
}
