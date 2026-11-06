// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_tag.h"

s32 ref_func_80C2291C(DmTag* this, PlayState* play) {
    s32 ret = false;

    if (((this->unk_18C & SUBS_OFFER_MODE_MASK) != SUBS_OFFER_MODE_NONE) &&
        Actor_TalkOfferAccepted(&this->actor, &play->state)) {
        this->unk_18C |= 8;
        SubS_SetOfferMode(&this->unk_18C, SUBS_OFFER_MODE_NONE, SUBS_OFFER_MODE_MASK);
        this->msgScript = DmTag_GetMsgScript(this, play);
        this->actionFunc = ref_func_80C229FC;
        ret = true;
    }
    return ret;
}
