// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ingate.h"

void ref_func_80953EA4(BgIngate* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    Player_SetCsActionWithHaltedActors(play, &this->dyna.actor, PLAYER_CSACTION_58);
    player->unk_3A0.x = this->dyna.actor.world.pos.x;
    player->unk_3A0.z = this->dyna.actor.world.pos.z;
    this->unk160 &= ~0x4;
    this->unk16A = 0x1E;
    this->actionFunc = ref_func_80954340;
}
