// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_twig.h"

void ref_func_80AC0CC4(EnTwig* this, PlayState* play) {
    this->unk_170 = 3458.0f;
    this->unk_174 = 0.2f;
    this->unk_16C |= 1;
    DynaPoly_DisableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
    this->actionFunc = ref_func_80AC0D2C;
}
