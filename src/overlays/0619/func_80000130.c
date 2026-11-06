// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_moon_stone.h"

void ref_func_80C06640(ObjMoonStone* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    s16 sp1A = this->actor.yawTowardsPlayer - 0x8000;

    sp1A -= player->actor.shape.rot.y;
    if (Actor_TalkOfferAccepted(&this->actor, &play->state)) {
        this->actor.colChkInfo.health = 1;
        Message_StartTextbox(play, 0x5E3, &this->actor);
        ref_func_80C066F8(this);
    } else {
        s32 phi_v0 = ABS_ALT(sp1A);
        if (phi_v0 < 0x1555) {
            Actor_OfferTalk(&this->actor, play, 80.0f);
        }
    }
}
