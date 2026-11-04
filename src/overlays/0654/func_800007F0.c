// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_tag.h"

void DmTag_Update(Actor* thisx, PlayState* play) {
    DmTag* this = (DmTag*)thisx;

    ref_func_80C2291C(this, play);
    this->actionFunc(this, play);
    SubS_Offer(&this->actor, play, 40.0f, fabsf(this->actor.playerHeightRel) + 1.0f, PLAYER_IA_NONE,
               this->unk_18C & SUBS_OFFER_MODE_MASK);
    Actor_SetFocus(&this->actor, 0.0f);
}
