// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_rr.h"

void ref_func_808FAC80(EnRr* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    if ((this->unk_1F0 == 0) && ((this->collider2.base.atFlags & AT_HIT) || (this->collider1.base.atFlags & AT_HIT))) {
        this->collider1.base.atFlags &= ~AT_HIT;
        this->collider2.base.atFlags &= ~AT_HIT;
        if (play->grabPlayer(play, player)) {
            player->actor.parent = &this->actor;
            ref_func_808FA3F8(this, player);
        }
    }
}
