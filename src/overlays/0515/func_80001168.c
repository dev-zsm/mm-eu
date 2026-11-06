// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_dblue_balance.h"

void ref_func_80B83518(Actor* thisx, PlayState* play) {
    BgDblueBalance* this = (BgDblueBalance*)thisx;

    this->isSwitchFlagSet = Flags_GetSwitch(play, BGDBLUEBALANCE_GET_SWITCH_FLAG(&this->dyna.actor));

    this->actionFunc(this, play);

    if (this->unk_17F == 2) {
        this->unk_17E--;
        if (this->unk_17E <= 0) {
            CutsceneManager_Stop(this->dyna.actor.csId);
            this->unk_17F = 0;
        }
    } else if ((this->unk_17F != 0) && (this->unk_17F == 1)) {
        if (CutsceneManager_IsNext(this->dyna.actor.csId)) {
            CutsceneManager_StartWithPlayerCs(this->dyna.actor.csId, &this->dyna.actor);
            this->unk_17F = 2;
            this->unk_17E = 0x50;
        } else {
            CutsceneManager_Queue(this->dyna.actor.csId);
        }
    }
    this->isSwitchFlagSet2 = this->isSwitchFlagSet;
}
