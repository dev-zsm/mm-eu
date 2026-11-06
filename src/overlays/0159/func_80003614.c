// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_goroiwa.h"

void ref_func_80941EB4(EnGoroiwa* this) {
    static s16 ref_D_80942EAC[] = { 20, 6, 20 };

    this->actionFunc = ref_func_80941F10;
    this->actor.speed = 0.0f;
    ref_func_8093EAB0(this, 6);
    this->unk_1C8 = ref_D_80942EAC[this->actor.home.rot.z & 3];
    this->unk_1C4 = 0.0f;
}
