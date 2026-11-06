// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ingate.h"

void ref_func_809541B8(BgIngate* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    if (this->unk160 & 0x4) {
        if ((player->transformation == PLAYER_FORM_HUMAN) && (player->actor.bgCheckFlags & BGCHECKFLAG_GROUND) &&
            (this->dyna.actor.xzDistToPlayer < 40.0f)) {
            if (this->dyna.actor.playerHeightRel > 15.0f) {
                Player_SetCsActionWithHaltedActors(play, &this->dyna.actor, PLAYER_CSACTION_WAIT);
                this->dyna.actor.textId = 0x9E6;
                Message_StartTextbox(play, this->dyna.actor.textId, NULL);
                this->actionFunc = ref_func_809543D4;
            }
        }
    } else if (!DynaPolyActor_IsPlayerOnTop(&this->dyna)) {
        this->unk160 |= 4;
    }
}
