// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_goroiwa.h"

void ref_func_8093ECD4(EnGoroiwa* this) {
    s32 params = ENGOROIWA_GET_300(&this->actor);

    if (this->unk_1D8 < 0) {
        if ((params == ENGOROIWA_300_0) || (params == ENGOROIWA_300_1)) {
            this->unk_1D8 = this->unk_1D4 - 1;
            this->unk_1DA = -1;
            this->unk_1D6 = this->unk_1D4;
        } else if (params == ENGOROIWA_300_3) {
            this->unk_1D6 = 0;
            this->unk_1D8 = 1;
            this->unk_1DA = 1;
        }
    } else if (this->unk_1D4 < this->unk_1D8) {
        if ((params == ENGOROIWA_300_0) || (params == ENGOROIWA_300_1)) {
            this->unk_1D6 = 0;
            this->unk_1D8 = 1;
            this->unk_1DA = 1;
        } else if (params == ENGOROIWA_300_3) {
            this->unk_1D6 = this->unk_1D4;
            this->unk_1D8 = this->unk_1D4 - 1;
            this->unk_1DA = -1;
        }
    }
}
