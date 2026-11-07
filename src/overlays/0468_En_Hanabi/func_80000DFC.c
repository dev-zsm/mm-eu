// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_hanabi.h"

void EnHanabi_Update(Actor* thisx, PlayState* play) {
    EnHanabi* this = (EnHanabi*)thisx;

    this->actionFunc(this, play);

    ref_func_80B22E0C(this->unk_148);
}
