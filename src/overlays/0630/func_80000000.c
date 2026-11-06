// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_iknin_susceil.h"

bool ref_func_80C0A740(BgIkninSusceil* this, PlayState* play) {
    s32 pad2[2];
    Vec3f offset;
    Player* player = GET_PLAYER(play);

    Actor_WorldToActorCoords(&this->dyna.actor, &offset, &player->actor.world.pos);

    return (ref_D_80C0B0E8.x < offset.z) && (offset.z < ref_D_80C0B0E8.z) && (offset.x > -240.0f) && (offset.x < ref_D_80C0B0E4);
}
