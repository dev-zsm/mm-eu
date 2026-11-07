// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_goroiwa.h"

void ref_func_80941F54(EnGoroiwa* this) {
    this->actionFunc = ref_func_80941FA4;
    ref_func_8093EAB0(this, 7);
    this->unk_1C4 = 0.0f;
    this->actor.velocity.y = fabsf(this->actor.speed) * 0.1f;
}
