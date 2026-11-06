// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_switch.h"

void ref_func_80B15A68(BgHakuginSwitch* this, PlayState* play) {
    s32 pad;
    BgHakuginSwitchStruct* s = &ref_D_80B1688C[BGHAKUGINSWITCH_GET_7(&this->dyna.actor)];
    s32 sp18 = !(s->unk_14 & 0x40);

    if (CutsceneManager_IsNext(this->curCsId)) {
        if (sp18) {
            CutsceneManager_StartWithPlayerCs(this->curCsId, &this->dyna.actor);
            this->unk_1BF = 40;
        }
        this->unk_1B4(this, play);
    } else if (sp18) {
        CutsceneManager_Queue(this->curCsId);
    }
}
