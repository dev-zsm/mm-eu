// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_switch.h"

void ref_func_80B161A0(BgHakuginSwitch* this, PlayState* play) {
    if (CutsceneManager_IsNext(this->curCsId)) {
        CutsceneManager_StartWithPlayerCs(this->curCsId, &this->dyna.actor);
        if (this->unk_1BE != 0) {
            Flags_SetSwitch(play, BGHAKUGINSWITCH_GET_SWITCH_FLAG(&this->dyna.actor));
        } else {
            Flags_UnsetSwitch(play, BGHAKUGINSWITCH_GET_SWITCH_FLAG(&this->dyna.actor));
        }
        this->unk_1BF = 50;
        this->unk_1B4(this, play);
    } else {
        CutsceneManager_Queue(this->curCsId);
    }
}
