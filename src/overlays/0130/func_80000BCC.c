// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_rr.h"

void ref_func_808FA9CC(EnRr* this) {
    s32 i;

    this->unk_1F2 = 0;
    this->unk_1F4 = 0;
    this->unk_1F6 = 2500;
    this->unk_1F8 = 0;
    this->unk_1FA = 0;
    this->unk_200 = 0.0f;
    this->unk_204 = 0.15f;
    this->unk_208 = 0.0f;
    this->unk_20C = 0x800;

    for (i = 0; i < ARRAY_COUNT(this->unk_324); i++) {
        this->unk_324[i].unk_08 = 1.0f;
        this->unk_324[i].unk_0C = 1.0f;
        this->unk_324[i].unk_14 = 0;
        this->unk_324[i].unk_16 = 0;
        this->unk_324[i].unk_18 = 0;
    }

    this->actionFunc = ref_func_808FB710;
}
