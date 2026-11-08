// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_goroiwa.h"

void ref_func_80941FA4(EnGoroiwa* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    if (ref_func_8094156C(this, play) == 0) {
        if ((this->collider.base.atFlags & AT_HIT) && !(player->stateFlags3 & PLAYER_STATE3_80000)) {
            ref_func_800B8D50(play, &this->actor, 2.0f, this->actor.yawTowardsPlayer, 0.0f, 0);
            Player_PlaySfx(player, NA_SE_PL_BODY_HIT);
            if (((this->actor.home.rot.z & 3) == 1) || ((this->actor.home.rot.z & 3) == 2)) {
                this->unk_1CC = 50;
            }
        } else if (ref_func_8093F5EC(this)) {
            ref_func_8093FC00(this);
            ref_func_809419D0(this);
            this->actor.speed = 0.0f;
        }
    }
}
