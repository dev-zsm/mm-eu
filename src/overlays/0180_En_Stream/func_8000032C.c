// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_stream.h"

void EnStream_WaitForPlayer(EnStream* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    s32 pad;
    Vec3f temp;

    if (EnStream_PlayerIsInRange(&this->actor.world.pos, &player->actor.world.pos, &temp, this->actor.scale.y) !=
        EN_STREAM_PLAYER_OUTSIDE_RANGE) {
        EnStream_SetupAction(this, EnStream_SuckPlayer);
    }
}
