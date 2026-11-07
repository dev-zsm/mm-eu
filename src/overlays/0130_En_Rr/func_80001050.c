// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_rr.h"

void ref_func_808FAE50(EnRr* this, PlayState* play) {
    s32 i;
    EnRrStruct* ptr;

    if (this->actionFunc != ref_func_808FB42C) {
        for (i = 0; i < ARRAY_COUNT(this->unk_324); i++) {
            ptr = &this->unk_324[i];
            ptr->unk_10 = Math_CosS(this->unk_1F2 + (i * 0x4000)) * this->unk_200;
        }

        if (this->unk_1E1 == 0) {
            for (i = 1; i < ARRAY_COUNT(this->unk_324); i++) {
                ptr = &this->unk_324[i];
                ptr->unk_14 = Math_CosS(this->unk_1F2 + (i * this->unk_1F8)) * this->unk_208;
                ptr->unk_18 = Math_SinS(this->unk_1F2 + (i * this->unk_1FA)) * this->unk_208;
            }
        }
    }

    if (this->unk_1EE == 0) {
        this->unk_1F2 += this->unk_1F4;
    }
}
