// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_hina.h"

void ref_func_80A1F470(DmHina* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    Math_SmoothStepToF(&this->unk148, 0.6f, 0.5f, 0.05f, 0.001f);
    this->unk154 = Math_SinS(play->gameplayFrames * 0x708) * 8.0f;
    if ((player->stateFlags1 & PLAYER_STATE1_400) && (this->actor.xzDistToPlayer < 80.0f)) {
        this->isDrawn = false;
        this->unk154 = 0.0f;
        this->actor.world.pos.y += 40.0f;
        this->actionFunc = ref_func_80A1F56C;
    }
}
