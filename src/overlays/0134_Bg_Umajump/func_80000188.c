// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_umajump.h"

void BgUmajump_CheckDistance(BgUmajump* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    if ((this->horse != NULL) && (player != NULL) &&
        (Math3D_Dist2D(this->horse->world.pos.x, this->horse->world.pos.z, player->actor.world.pos.x,
                       player->actor.world.pos.z) < 1400.0f)) {
        this->actionFunc = BgUmajump_PlayCutscene;
    }
}
