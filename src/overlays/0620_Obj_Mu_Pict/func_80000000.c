// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_mu_pict.h"

void ObjMuPict_Init(Actor* thisx, PlayState* play) {
    ObjMuPict* this = (ObjMuPict*)thisx;

    if (!CHECK_WEEKEVENTREG(WEEKEVENTREG_75_20) && !CHECK_WEEKEVENTREG(WEEKEVENTREG_CLEARED_STONE_TOWER_TEMPLE)) {
        Actor_Kill(&this->actor);
    }

    ref_func_80C06D90(this, play);
    this->unk14A = OBJMUPICT_GET_F000(&this->actor);
    this->actor.attentionRangeType = ATTENTION_RANGE_6;
    this->actor.focus.pos = this->actor.world.pos;
    this->actor.focus.pos.y += 30.0f;
    this->unk148 = 0;
    ref_func_80C06B5C(this);
}
