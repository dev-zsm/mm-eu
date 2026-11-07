// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_sda.h"

void EnSda_Draw(Actor* thisx, PlayState* play) {
    EnSda* this = (EnSda*)thisx;
    Player* player;
    u8* shadowTex = GRAPH_ALLOC(play->state.gfxCtx, 64 * 64);

    if (this->actor.params == ENSDA_1) {
        player = (Player*)this->actor.parent;
    } else {
        player = GET_PLAYER(play);
    }

    player->actor.shape.shadowAlpha = 0;
    ref_func_8094702C(this, shadowTex, player, play);

    if (KREG(0) < 5) {
        ref_func_80947668(shadowTex, player, play);
    }
}
