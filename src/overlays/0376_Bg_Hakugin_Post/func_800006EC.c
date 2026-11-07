// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_post.h"

void ref_func_80A9B3BC(BgHakuginPost* this, PlayState* play) {
    s32 pad;
    s32 switchFlag1 = BGHAKUGINPOST_GET_SWITCH_FLAG(&this->dyna.actor);
    s32 switchFlag2 = BGHAKUGINPOST_GET_SWITCH_FLAG(&this->dyna.actor) + 1;
    s32 sp20;
    s32 sp1C;

    if (Flags_GetSwitch(play, switchFlag1)) {
        sp20 = true;
    } else {
        sp20 = false;
    }

    if (Flags_GetSwitch(play, switchFlag2)) {
        sp1C = true;
    } else {
        sp1C = false;
    }

    if (!(sp20 | sp1C)) {
        Flags_SetSwitch(play, switchFlag1);
        this->unk_170 = true;
    } else {
        this->unk_170 = sp20;
    }

    this->unk_174 = sp1C;
}
