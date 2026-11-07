// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_spout_fire.h"

s32 ref_func_80A60C24(BgSpoutFire* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    Vec3f sp18;

    Actor_WorldToActorCoords(&this->actor, &sp18, &player->actor.world.pos);
    if ((fabsf(sp18.x) < 100.0f) && (fabsf(sp18.z) < 120.0f)) {
        return true;
    } else {
        return false;
    }
}
