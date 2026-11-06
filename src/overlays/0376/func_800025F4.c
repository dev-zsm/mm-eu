// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_post.h"

void ref_func_80A9D2C4(BgHakuginPost* this, BgHakuginPostFunc unkFunc, f32 arg2, s16 csId, s16 additionalCsId) {
    this->unkFunc = unkFunc;
    this->csId = csId;
    this->additionalCsId = additionalCsId;
    this->csLength = -1;
    this->csLength = CutsceneManager_GetLength(csId);
    if (this->csLength < 0) {
        this->csLength = 15;
    }
    this->dyna.actor.focus.pos.x = this->dyna.actor.home.pos.x;
    this->dyna.actor.focus.pos.y = this->unk_16C + arg2;
    this->dyna.actor.focus.pos.z = this->dyna.actor.home.pos.z;
    this->actionFunc = ref_func_80A9D360;
}
