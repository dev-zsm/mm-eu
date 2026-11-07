// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_spdweb.h"

void ref_func_809CE15C(BgSpdweb* this) {
    this->unk_2F8[0].y = this->unk_2F8[3].y = this->unk_2F8[10].y = this->unk_2F8[11].y = this->unk_2F8[12].y =
        this->unk_2F8[13].y = this->unk_2F8[14].y = this->unk_2F8[15].y =
            (this->dyna.actor.home.pos.y - this->dyna.actor.world.pos.y) * 10.0f;
}
