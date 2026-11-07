// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_mkk.h"

void ref_func_80A4EDF0(EnMkk* this) {
    this->alpha = 0;
    this->unk_14B |= 3;
    this->actor.flags &= ~ACTOR_FLAG_ATTENTION_ENABLED;
    this->actor.draw = NULL;
    this->actor.update = ref_func_80A4F16C;
    this->actor.gravity = -0.5f;
    this->unk_14E = this->unk_152;
    this->actionFunc = ref_func_80A4EE48;
}
