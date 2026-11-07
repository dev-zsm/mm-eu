// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_post.h"

void ref_func_80A9D360(BgHakuginPost* this, PlayState* play) {
    if (CutsceneManager_IsNext(this->csId)) {
        CutsceneManager_StartWithPlayerCs(this->csId, &this->dyna.actor);
        if (this->additionalCsId > CS_ID_NONE) {
            ref_func_80A9D3E4(this);
        } else {
            this->unkFunc(this);
        }
    } else {
        CutsceneManager_Queue(this->csId);
    }
}
