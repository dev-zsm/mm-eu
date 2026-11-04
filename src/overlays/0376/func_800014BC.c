// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_post.h"

void BgHakuginPost_RequestQuakeAndRumble(BgHakuginPost* this, PlayState* play) {
    s32 pad;
    Player* player = GET_PLAYER(play);
    Camera* activeCam = GET_ACTIVE_CAM(play);
    s16 quakeIndex;

    Rumble_Request(Math3D_Dist2DSq(player->actor.world.pos.x, player->actor.world.pos.z, this->dyna.actor.home.pos.x,
                                   this->dyna.actor.home.pos.z),
                   255, 20, 150);

    quakeIndex = Quake_Request(activeCam, QUAKE_TYPE_3);
    Quake_SetSpeed(quakeIndex, 17232);
    Quake_SetPerturbations(quakeIndex, 6, 0, 0, 0);
    Quake_SetDuration(quakeIndex, 20);
}
