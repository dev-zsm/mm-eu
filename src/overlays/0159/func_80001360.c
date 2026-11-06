// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_goroiwa.h"

void ref_func_8093FC00(EnGoroiwa* this) {
    s32 params = ENGOROIWA_GET_300(&this->actor);

    ref_func_8093ED80(this);
    if (((params == ENGOROIWA_300_0) || (params == ENGOROIWA_300_1)) &&
        ((this->unk_1D6 == 0) || (this->unk_1D6 == this->unk_1D4))) {
        ref_func_8093EE64(this, this->unk_1D6);
    }
}
