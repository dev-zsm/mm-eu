// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_switch.h"

void ref_func_80B1606C(BgHakuginSwitch* this, PlayState* play) {
    BgHakuginSwitchStruct* s = &ref_D_80B1688C[BGHAKUGINSWITCH_GET_7(&this->dyna.actor)];

    if (s->unk_14 & 0x80) {
        ref_func_80B15790(this, NA_SE_EV_STONE_SWITCH_OFF);
    }
    this->unk_1C0 = 1;
    this->actionFunc = ref_func_80B160DC;
}
