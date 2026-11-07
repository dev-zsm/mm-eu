// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_switch.h"

void ref_func_80B15F88(BgHakuginSwitch* this, PlayState* play) {
    s32 phi_a0;
    BgHakuginSwitchStruct* sp18 = &ref_D_80B1688C[BGHAKUGINSWITCH_GET_7(&this->dyna.actor)];
    s32 phi_v1;

    if (Flags_GetSwitch(play, BGHAKUGINSWITCH_GET_SWITCH_FLAG(&this->dyna.actor))) {
        phi_a0 = true;
    } else {
        phi_a0 = false;
    }

    if (sp18->unk_14 & 4) {
        phi_v1 = true;
    } else {
        phi_v1 = false;
    }

    if (phi_a0 != phi_v1) {
        if ((sp18->unk_14 & 0xFF) & 0x20) {
            if (ref_D_80B16AF0 < play->gameplayFrames) {
                ref_func_80B15A4C(this, ref_func_80B1606C, this->additionalCsId);
            }
        } else {
            ref_func_80B1606C(this, play);
        }
    }
}
