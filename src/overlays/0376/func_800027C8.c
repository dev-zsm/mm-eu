// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_post.h"

void BgHakuginPost_Update(Actor* thisx, PlayState* play) {
    BgHakuginPost* this = (BgHakuginPost*)thisx;
    f32 temp;

    ref_func_80A9B46C(this, play);
    if ((this->csLength >= 0) && ((this->actionFunc != ref_func_80A9D260) || (this->actionFunc != ref_func_80A9D360))) {
        this->csLength--;
        if (this->csLength < 0) {
            CutsceneManager_Stop(this->csId);
        }
    }

    if ((this->additionalCsLength >= 0) && (this->actionFunc != ref_func_80A9D434)) {
        this->additionalCsLength--;
        if (this->additionalCsLength < 0) {
            CutsceneManager_Stop(this->additionalCsId);
        }
    }

    if (this->unk_178 > 0) {
        this->unk_178--;
    }

    if (this->unk_179 > 0) {
        this->unk_179--;
    }

    ref_func_80A9BC0C(&ref_D_80A9E028);
    this->actionFunc(this, play);
    ref_func_80A9BD24(this, play, &ref_D_80A9E028);
    ref_func_80A9C058(this, play, &ref_D_80A9E028);
    ref_func_80A9C228(this, play, &ref_D_80A9E028);
    temp = ref_func_80A9B2B8(&ref_D_80A9E028);
    this->dyna.actor.scale.y = temp + this->unk_16C - this->dyna.actor.home.pos.y;
    this->dyna.actor.scale.y *= 0.0025f;
    if (thisx->scale.y < 0.0001f) {
        thisx->scale.y = 0.0001f;
    }

    ref_func_80A9C854(this, play);
}
