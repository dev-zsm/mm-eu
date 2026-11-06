// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_rr.h"

void ref_func_808FAF94(EnRr* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    Math_SmoothStepToS(&this->actor.shape.rot.y, this->actor.yawTowardsPlayer, 10, 0x1F4, 0);
    this->actor.world.rot.y = this->actor.shape.rot.y;
    if ((this->unk_1E6 == 0) && !(player->stateFlags2 & PLAYER_STATE2_80) &&
        (Player_GetMask(play) != PLAYER_MASK_STONE) &&
        (this->actor.xzDistToPlayer < (8421.053f * this->actor.scale.x))) {
        ref_func_808FA260(this);
    } else if ((this->actor.xzDistToPlayer < 400.0f) && (this->actor.speed == 0.0f)) {
        ref_func_808FA238(this, 2.0f);
    }
}
