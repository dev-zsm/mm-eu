// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_iknin_susceil.h"

void BgIkninSusceil_Update(Actor* thisx, PlayState* play) {
    s32 pad;
    BgIkninSusceil* this = (BgIkninSusceil*)thisx;
    Player* player = GET_PLAYER(play);

    if ((this->unk168 == 0) && (this->unk166 > 0) && (player->stateFlags3 & PLAYER_STATE3_100) &&
        (player->unk_B48 > 1000.0f)) {
        this->unk168 = 2;
        if ((ref_func_80C0A95C(this, play) != 0) && (this->actionFunc != ref_func_80C0AE5C)) {
            Player_PlaySfx(player, NA_SE_PL_BODY_HIT);
            ref_func_80C0AE3C(this);
        }
    }

    if (this->unk168 > 0) {
        this->unk168--;
    }

    this->actionFunc(this, play);

    if ((this->dyna.actor.home.pos.y + 70.0f) < this->dyna.actor.world.pos.y) {
        this->unk166 = 0;
    } else if (player->stateFlags3 & PLAYER_STATE3_100) {
        this->unk166 = 3;
    } else {
        if (this->unk166 > 0) {
            this->unk166--;
        }
    }
    if (this->unk166 > 0) {
        ref_func_80C0A838(this, play);
    } else {
        ref_func_80C0A804(this, play);
    }
}
