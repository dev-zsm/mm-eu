// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_switch.h"

void ref_func_80B15F3C(BgHakuginSwitch* this, PlayState* play) {
    BgHakuginSwitchStruct* s = &ref_D_80B1688C[BGHAKUGINSWITCH_GET_7(&this->dyna.actor)];

    this->dyna.actor.world.pos.y = s->unk_4 + this->dyna.actor.home.pos.y;
    this->unk_1C0 = 0;
    this->actionFunc = ref_func_80B15F88;
}
