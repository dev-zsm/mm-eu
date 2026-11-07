// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_goron_oyu.h"

void ref_func_80B4009C(BgGoronOyu* this) {
    this->unk_17E = 0;
    this->initCsId = this->dyna.actor.csId;
    this->actionFunc = ref_func_80B40100;
    this->unk_164 = 20.0f;
}
