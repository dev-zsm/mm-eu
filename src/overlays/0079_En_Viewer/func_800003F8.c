// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_viewer.h"

void ref_func_8089F218(EnViewer* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    f32 xzDist = fabsf(this->actor.xzDistToPlayer);
    f32 temp;

    if ((play->roomCtx.curRoom.num == this->actor.room) && (xzDist <= this->unk_148) &&
        (this->actor.playerHeightRel <= this->unk_150) && (this->actor.world.pos.y <= player->actor.world.pos.y)) {
        temp = (xzDist - this->unk_14C) / (this->unk_148 - this->unk_14C);
        ref_func_8089F014(this, play, temp);
    } else {
        ref_func_8089F0A0(this, play);
    }
}
