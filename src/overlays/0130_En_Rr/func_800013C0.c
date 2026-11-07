// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_rr.h"

void ref_func_808FB1C0(EnRr* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    Rumble_Request(this->actor.xyzDistToPlayerSq, 120, 2, 120);
    if (!(this->unk_1E4 & 7)) {
        Actor_PlaySfx(&this->actor, NA_SE_EN_EYEGOLE_DEMO_EYE);
    }

    player->av2.actionVar2 = 0;
    this->unk_1F0 = 8;
    this->unk_1EA--;

    if (this->unk_1EA == 0) {
        ref_func_808FA7AC(this);
    } else {
        Math_StepToF(&player->actor.world.pos.x, this->unk_228.x, 30.0f);
        Math_StepToF(&player->actor.world.pos.y, this->unk_228.y + this->unk_218, 30.0f);
        Math_StepToF(&player->actor.world.pos.z, this->unk_228.z, 30.0f);
        Math_StepToF(&this->unk_218, -(f32)this->collider1.dim.height, 5.0f);
    }
}
