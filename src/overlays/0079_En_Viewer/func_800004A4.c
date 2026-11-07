// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_viewer.h"

void ref_func_8089F2C4(EnViewer* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    Vec3f sp20;
    f32 temp;

    Actor_WorldToActorCoords(&this->actor, &sp20, &player->actor.world.pos);

    if (this->unk_14C == 0.0f) {
        this->unk_14C = 0.1f;
    }

    if ((play->roomCtx.curRoom.num == this->actor.room) && (sp20.x < fabsf(this->unk_148))) {
        temp = sp20.z / this->unk_14C;
        ref_func_8089F014(this, play, temp);
    } else {
        ref_func_8089F0A0(this, play);
    }
}
