// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_goroiwa.h"

void ref_func_8093EE18(EnGoroiwa* this, PlayState* play) {
    this->unk_1D4 = play->setupPathList[ENGOROIWA_GET_PATH_INDEX(&this->actor)].count - 1;
    this->unk_1D6 = this->actor.home.rot.y;
    this->unk_1D8 = this->unk_1D6 + 1;
    this->unk_1DA = 1;
}
