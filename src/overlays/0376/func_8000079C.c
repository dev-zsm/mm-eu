// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_post.h"

void ref_func_80A9B46C(BgHakuginPost* this, PlayState* play) {
    s32 pad;
    s32 switchFlag1 = BGHAKUGINPOST_GET_SWITCH_FLAG(&this->dyna.actor);
    s32 switchFlag2 = BGHAKUGINPOST_GET_SWITCH_FLAG(&this->dyna.actor) + 1;
    s32 sp28;
    s32 sp24;

    if (Flags_GetSwitch(play, switchFlag1)) {
        sp28 = true;
    } else {
        sp28 = false;
    }

    if (Flags_GetSwitch(play, switchFlag2)) {
        sp24 = true;
    } else {
        sp24 = false;
    }

    if (!this->unk_170 && (sp28 == 1)) {
        Flags_UnsetSwitch(play, switchFlag2);
    } else if (!this->unk_174 && (sp24 == 1)) {
        Flags_UnsetSwitch(play, switchFlag1);
    }

    this->unk_170 = sp28;
    this->unk_174 = sp24;
}
