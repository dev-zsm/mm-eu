// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_col_man.h"

void ref_func_80AFDE00(EnColMan* this, PlayState* play) {
    if (this->actor.bgCheckFlags & BGCHECKFLAG_GROUND) {
        if (this->actor.params == EN_COL_MAN_HEART_PIECE) {
            this->actor.params = EN_COL_MAN_RECOVERY_HEART;
            this->actor.speed = 2.0f;
            this->actor.velocity.y = 8.0f;
        } else {
            this->actor.speed = 0.0f;
        }
    }
    if (!CHECK_WEEKEVENTREG(WEEKEVENTREG_RECEIVED_MARINE_RESEARCH_LAB_FISH_HEART_PIECE)) {
        this->actor.shape.rot.y += 0x3E8;
    }
    if (Actor_HasParent(&this->actor, play)) {
        this->actor.parent = NULL;
        this->actor.draw = NULL;
        this->actionFunc = EnColMan_SetHeartPieceCollectedAndKill;
    } else if (!CHECK_WEEKEVENTREG(WEEKEVENTREG_RECEIVED_MARINE_RESEARCH_LAB_FISH_HEART_PIECE)) {
        Actor_OfferGetItem(&this->actor, play, GI_HEART_PIECE, 40.0f, 40.0f);
    } else {
        Actor_OfferGetItem(&this->actor, play, GI_RECOVERY_HEART, 40.0f, 40.0f);
    }
}
